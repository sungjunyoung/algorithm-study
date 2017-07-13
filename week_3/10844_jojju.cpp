#include <iostream>
using namespace std;
#define MAX_NUM 100
long long int cache[10][MAX_NUM + 1];

long long int recursiveFind(int curNum, int depth) {
    if (curNum == -1 || curNum == 10)
        return 0;

    if (depth == 1)
        return 1;

    if (cache[curNum][depth]) {
        return cache[curNum][depth];
    }

    return cache[curNum][depth] = (recursiveFind(curNum - 1, depth - 1) + recursiveFind(curNum + 1, depth - 1)) % 1000000000;
}

int main() {
    int depth;
    cin >> depth;
    long long int sum = 0;

    for (int i = 1; i <= 9; ++i)
        sum += recursiveFind(i, depth);

    cout << sum % 1000000000;

    return 0;
}