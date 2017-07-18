//
// Created by 성준영 on 2017. 7. 18..
//

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

bool isDecreaseNum(long long int number) {
    int digit = -1;
    bool flag = true;

    if (number / 10 == 0) {
        return true;
    }

    while (number != 0) {
        if (digit < number % 10) {
            digit = number % 10;
        } else {
            flag = false;
            break;
        }
        number /= 10;
    }

    return flag;
}

long long int getDigitNum(long long int number, int digit) {
    for (int i = 0; i < digit - 1; i++) {
        number /= 10;
    }
    number %= 10;
    return number;
}

int getDigit(long long int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        count++;
    }
    return count;
}

long long int changeNum(long long int number) {

    int digit = getDigit(number);
    for (int i = digit; i > 1; i--) {
        if (getDigitNum(number, i) <= getDigitNum(number, i - 1)) {
            number /= pow(10, i - 1);
            number += 1;
            number *= pow(10, i - 1);
            return number;
        }
    }

}

int main() {

    int n;
    cin >> n;

    int count = 0;
    int number = 0;

    if (n > 1022) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 1022) {
        cout << 9876543210 << endl;
        return 0;
    } // FUCK
    while (1) {
        if (!isDecreaseNum(number)) {
            // 숫자 점프
            number = changeNum(number);
        } else {
            if (count == n) {
                cout << number << endl;
                return 0;
            }
            number++;
            count++;
        }
    }
}