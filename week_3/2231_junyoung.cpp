//
// Created by 성준영 on 2017. 7. 18..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getDigitSum(int n) {
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int getDigit(int n) {
    int result = 0;
    while (n != 0) {
        n /= 10;
        result++;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    int digit = getDigit(n);
    int maxPartition = 9 * digit;
    int startPoint = n - maxPartition;

    for (int i = startPoint; i <= n; i++) {
        if (getDigitSum(i) + i == n) {
            // 생성자 존재
            cout << i << endl;
            return 0;
        }
    }

    // 생성자 없음
    cout << 0 << endl;
}
