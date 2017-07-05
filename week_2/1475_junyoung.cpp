//
// Created by 성준영 on 2017. 7. 02..
//

#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 각 자리수 갯수를 체크하기위한 배열
    int checkList[10] = {0};

    int num;
    while (n != 0) {
        num = n % 10;
        // num 이 9 혹은 6이면 6으로 몰아주기
        if (num == 9 || num == 6) {
            num = 6;
        }
        checkList[num]++;

        n = n / 10;
    }

    // 몰아준 6이 짝수/홀수에 따라 값 바꾸기
    if (checkList[6] % 2 == 0) {
        checkList[6] = checkList[6] / 2;
    } else {
        checkList[6] = checkList[6] / 2 + 1;
    }

    // 최대값 뽑아내기
    int max = 0;
    for (int i = 0; i < 10; i++) {
        if(checkList[i] > max){
            max = checkList[i];
        }
    }
    cout << max << endl;
}