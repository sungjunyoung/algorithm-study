#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

// 직접구현해보고싶다..
int main() {
    int n;
    cin >> n;

    vector<int> numList;
    for (int i = 1; i <= n; i++) {
        int tempNum;
        scanf("%d",&tempNum);
        numList.push_back(tempNum);
    }

    sort(numList.begin(), numList.end());

    for (int i = 0; i < n; i++) {
        printf("%d\n", numList[i]);
    }
}