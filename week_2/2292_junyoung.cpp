//
// Created by 성준영 on 2017. 7. 02..
//


#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    // 시작점이 1일때 그냥 1로 리턴
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    int iter = 2;
    int result = 1;
    // 규칙 발견 ( 5, 11, 17 만큼의 차이씩 result 는 1 만큼 증가함 )
    while (iter <= n) {
        iter += 6 * result;
        result += 1;
    }
    cout << result << endl;
}