//
// Created by 성준영 on 2017. 7. 02..
//

#include <iostream>

using namespace std;

int D[15][15];

int main() {
    // 0 층 초기화
    for (int i = 0; i <= 14; i++) {
        D[0][i] = i;
    }

    // 정답이 될수 있는 모든 경우 전체 초기화 (최대 14*14*14 이므로 무리 X)
    for (int i = 1; i <= 14; i++) {
        for (int j = 1; j <= 14; j++) {
            int sum = 0;
            for (int k = 1; k <= j; k++) {
                sum += D[i - 1][k];
            }
            D[i][j] = sum;
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;

        // 출력
        cout << D[k][n] << endl;
    }
}