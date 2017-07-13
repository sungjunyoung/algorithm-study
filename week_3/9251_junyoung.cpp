#include <iostream>

using namespace std;

int main() {
    string a;
    string b;

    cin >> a >> b;

    string temp;
    if (a.length() > b.length()) {
        temp = a;
        a = b;
        b = temp;
    }

    int D[1001][1001];
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            D[i][j] = 0;
        }
    }

    // 초기값설정
    for (int i = 0; i < a.length(); i++) {
        if (b[0] == a[i]) {
            if (i == 0) {
                D[i][0]++;
            } else {
                if (D[i - 1][0] == 1)
                    D[i][0] = D[i - 1][0];
                else {
                    D[i][0] = 1;
                }
            }
        } else {
            if (i != 0) {
                D[i][0] = D[i - 1][0];
            }
        }
    }

    for (int i = 1; i < b.length(); i++) {
        if (a[0] == b[i]) {
            if (D[0][i - 1] == 1)
                D[0][i] = D[0][i - 1];
            else {
                D[0][i] = 1;
            }
        } else {
            if (i != 0) {
                D[0][i] = D[0][i - 1];
            }
        }
    }


    for (int i = 1; i < b.length(); i++) {
        for (int j = 1; j < a.length(); j++) {
            if (b[i] == a[j]) {
                D[j][i] = D[j - 1][i - 1] + 1;
            } else {
                D[j][i] = max(D[j][i - 1], D[j - 1][i]);

            }
        }
    }

    cout << D[a.length() - 1][b.length() - 1] << endl;

}
