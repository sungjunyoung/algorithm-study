//
// Created by 성준영 on 2017. 7. 13..
//
#include <iostream>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    // 곱셈 결과
    int mul = A * B * C;
    int result[10] = {0};

    while (mul != 0) {
        int num = mul % 10;
        result[num]++;
        mul = mul / 10;
    }

    for (int i = 0; i < 10; i++) {
        cout << result[i] << endl;
    }
}