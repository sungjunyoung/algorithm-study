//
// Created by 성준영 on 2017. 4. 12..
//

#include <iostream>
using namespace std;
// 셀프넘버 함수
int d(int n) {
    int res = n;
    while (n != 0) {
        res += n % 10;
        n = n / 10;
    }
    return res;
}

int main() {
    // 배열 초기화
    int list[10001] = {0};

    for (int i = 1; i <= 10000; i++) {
        // 자릿수를 넘으면 넘어감
        if(d(i) > 10000){
            continue;
        }
        // 셀프넘버가 만들어지는 곳을 1로 체크해준다.
        list[d(i)] = 1;
    }
    for (int i = 1; i <= 10000; i++) {
        if(list[i] == 0){
            cout << i << endl;
        }
    }
}