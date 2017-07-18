//
// Created by 성준영 on 2017. 7. 15..
//

#include <iostream>
#include <math.h>

using namespace std;

int getInitialResult(int xy, int result, int count, int sum) {
    while (count != xy) {
        count++;
        result += sum;
        sum += 8;
    }
    return result;
}

int getNumber(int x, int y) {
    int count = 1;
    int result;
    int sum;
    if (x >= 0 && abs(y - 1) <= x) { // 아래쪽
        result = 2;
        sum = 7;
        result = getInitialResult(x + 1, result, count, sum);
        result = result + (y - 1);
    } else if (x < 0 && abs(y) < 0 - x) { // 위쪽
        result = 4;
        sum = 11;
        result = getInitialResult(abs(x) , result, count, sum);
        result = result - y;
    } else if (y > 0 && abs(x + 1) < y) { // 오른쪽
        result = 3;
        sum = 9;
        result = getInitialResult(y , result, count, sum);
        result = result - 1 - x;
    } else if (y <= 0 && abs(x) <= -y) { // 왼쪽
        result = 1;
        sum = 5;
        result = getInitialResult(abs(y) + 1, result, count, sum);
        result = result + x;
    }

    return result;
}

int getDigit(int x, int y){
    int result = getNumber(x, y);
    int digit = 0;
    while(result != 0){
        result /= 10;
        digit +=1;
    }
    return digit;
}

int main() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int maxDigit = max(getDigit(r1, c1), getDigit(r1, c2));
    maxDigit = max(maxDigit, getDigit(r2, c1));
    maxDigit = max(maxDigit, getDigit(r2, c2));

    for (int i = r1; i <= r2; i++) {
        for (int j = c1; j <= c2; j++) {
            printf("%*d ", maxDigit, getNumber(i, j));
        }
        printf("\n");
    }
}