#include <iostream>

using namespace std;
int order = 9;
int N;
int table[11][10];

void recursive(int order, int i, int j) {
    cout << j;
    order -= table[i + 1][j];

    if (i == 0) return;

    for (int k = i - 1; k < 10; ++k) {
        order += table[i][k];
        if (order >= N) {
            recursive(order, i - 1, k);
            break;
        }
    }
    return;
}

int main() {
    cin >> N;

    if (N <= 9)
        cout << N << endl;
    else if (N > 1022)
        cout << -1 << endl;
    else {

        for (int i = 1; i < 11; ++i) {

            for (int j = i - 1; j < 10; ++j) {
                if (i == 1) table[i][j] = 1;

                else {
                    if (j == i - 1) table[i][j] = 1;
                    else table[i][j] = table[i - 1][j - 1] + table[i][j - 1];

                    order += table[i][j];

                    if (order >= N) {
                        recursive(order, i - 1, j);
                        break;
                    }

                }
            }

            if (order >= N) break;
        }

    }

    return 0;
}