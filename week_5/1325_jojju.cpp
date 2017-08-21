#include <iostream>
#include <vector>

using namespace std;
#define MAX_N 10000
vector<int> tableVector[MAX_N + 1];
int cache[MAX_N + 1];
int N;
int M;

int recursive(int curNode) {
    if (cache[curNode] > 0) return 0;
    cache[curNode] = 1;
    for (int i = 0; i < tableVector[curNode].size(); ++i)
        cache[curNode] += recursive(tableVector[curNode][i]);
    return cache[curNode];
}

int main() {
    cin >> N >> M;
    int inputFirst, inputSecond;

    for (int i = 0; i < M; ++i) {
        cin >> inputFirst >> inputSecond;
        tableVector[inputSecond].push_back(inputFirst);
    }

    int maxNode = -1;
    int curRet;
    vector<int> output;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= N; ++j)
            cache[j] = 0;
        curRet = recursive(i);
        output.push_back(curRet);
        maxNode = max(maxNode, curRet);
    }

    for (int i = 0; i < output.size(); ++i) {
        if (maxNode == output[i])
            cout << i + 1 << ' ';
    }

    return 0;
}