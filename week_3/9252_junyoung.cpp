#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string a;
    string b;

    cin >> a >> b;

    int D[1001][1001] = {0,};

    // 길이 정렬
    if (a.length() > b.length()) {
        string temp = a;
        a = b;
        b = temp;
    }

    // DP 기저 설정
    if (a[0] == b[0])
        D[1][1] = 1;
    for (int i = 2; i <= a.length(); i++) {
        if (a[i - 1] != b[0]) {
            D[1][i] = D[1][i - 1];
        } else {
            if (D[1][i - 1] == 0) D[1][i] = D[1][i - 1] + 1;
            else D[1][i] = D[1][i - 1];
        }
    }
    for (int i = 2; i <= b.length(); i++) {
        if (a[0] != b[i - 1]) {
            D[i][1] = D[i - 1][1];
        } else {
            if (D[i - 1][1] == 0) D[i][1] = D[i - 1][1] + 1;
            else D[i][1] = D[i - 1][1];
        }
    }

    // DP
    for (int i = 2; i <= b.length(); i++) {
        for (int j = 2; j <= a.length(); j++) {
            if (a[j - 1] == b[i - 1]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            } else {
                D[i][j] = max(D[i][j - 1], D[i - 1][j]);
            }
        }
    }

    // Tracking
    int limitCounter = D[b.length()][a.length()];
    string result;
    int i = b.length();
    int j = a.length();

    while (1) {
        if (i == 0 || j == 0) {
            break;
        }

        if (a[j - 1] == b[i - 1]) {
            result = a[j - 1] + result;
            i--;
            j--;
        } else {
            if (D[i - 1][j] == D[i][j]) {
                i = i - 1;
            } else {
                j = j - 1;
            }
        }

    }


    cout << D[b.length()][a.length()] << endl;
    cout << result << endl;
}

