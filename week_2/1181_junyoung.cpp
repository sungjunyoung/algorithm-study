#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> wordList;
vector<string> wordCountList[51];

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char tempString[50];
        scanf("%50s", tempString);
        wordList.push_back(tempString);
    }

    for (int i = 0; i < n; i++) {
        wordCountList[wordList[i].size()].push_back(wordList[i]);
    }

    // 각 큐 소팅하기
    for (int i = 0; i <= 50; i++) {
        sort(wordCountList[i].begin(), wordCountList[i].end());
    }

    // 큐에서 꺼내면서 결과에 푸시
    vector<string> result;
    for (int i = 0; i <= 50; i++) {
        while (!wordCountList[i].empty()) {
            result.push_back(wordCountList[i].front());
            wordCountList[i].erase(wordCountList[i].begin(), wordCountList[i].begin() + 1);
        }
    }

    // 중복제거
    vector<string>::iterator pos;
    pos = unique(result.begin(), result.end());
    result.erase(pos, result.end());

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << endl;
    }
}