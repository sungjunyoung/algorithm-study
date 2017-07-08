#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numList;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        numList.push_back(num);
    }

    int sum = 0;
    for (int i = 0; i < numList.size(); i++) {
        sum += numList[i];
    }
    double average = (double) sum / (double) n;
    if (average >= 0) cout << (int) (average + 0.5) << endl;
    else cout << (int) (average - 0.5) << endl;

    sort(numList.begin(), numList.end());
    int midNum = numList[(n - 1) / 2];
    cout << midNum << endl;

    int numCount[8001] = {0,};
    for (int i = 0; i < numList.size(); i++) {
        numCount[4000 + numList[i]]++;
    }
    int max = -1;
    for (int i = 0; i < 8001; i++) {
        if (max < numCount[i]) {
            max = numCount[i];
        }
    }
    vector<int> maxs;
    for (int i = 0; i < 8001; i++) {
        if (max == numCount[i]) {
            maxs.push_back(i - 4000);
        }
    }

    if (maxs.size() > 1) {
        cout << maxs[1] << endl;
    } else {
        cout << maxs[0] << endl;
    }


    int maxMin = numList[n - 1] - numList[0];
    cout << maxMin << endl;
}