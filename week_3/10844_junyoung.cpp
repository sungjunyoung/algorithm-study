#include <iostream>

using namespace std;

//N 자리인 x 로 끝나는 계단수의 갯수
long long int D[101][10];

int main() {
    int n;
    cin >> n;

    D[1][0] = 0;
    for (int i = 1; i <= 9; i++) {
        D[1][i] = 1;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            if (j == 0) {
                D[i][j] = D[i - 1][j + 1];
            } else if (j == 9) {
                D[i][j] = D[i - 1][j - 1];
            } else {
                D[i][j] = D[i - 1][j - 1] + D[i - 1][j + 1];
            }

            D[i][j] %= 1000000000;
        }
    }

    long long int result = 0;
    for(int i=0;i<=9;i++){
        result += D[n][i];
        result %= 1000000000;
    }

    cout << result << endl;
}
