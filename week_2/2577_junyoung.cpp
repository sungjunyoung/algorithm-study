//
// Created by 성준영 on 2017. 7. 02..
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
        // 계속 떼어주면서 확인 후 결과 어레이에 저장
        int num = mul % 10;
        result[num]++;
        mul = mul / 10;
    }

    for(int i=0;i<10;i++){
        cout << result[i] << endl;
    }
}