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
    while (n != 0) {
        numList.push_back(n % 10);
        n /= 10;
    }

    sort(numList.begin(), numList.end());

    for (int i = numList.size() - 1; i >= 0; i--) {
        printf("%d", numList[i]);
    }
    printf("\n");
}