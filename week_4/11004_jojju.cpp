#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int n;
    int k;
    cin >> n >> k;

    vector<int> numList;
    for (int i = 1; i <= n; i++) {
        int tempNum;
        scanf("%d",&tempNum);
        numList.push_back(tempNum);
    }

    sort(numList.begin(), numList.end());

    cout<<numList[k - 1]<<endl;

}