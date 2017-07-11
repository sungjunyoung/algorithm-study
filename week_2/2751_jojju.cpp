#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int input;
    vector<int> array;
    for (int i = 1; i <= n; i++) {
        cin>>input;
        array.push_back(input);
    }

    sort(array.begin(), array.end());

    for (int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }
}