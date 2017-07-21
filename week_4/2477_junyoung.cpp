//
// Created by 성준영 on 2017. 7. 21..
//

#include <iostream>
#include <vector>

using namespace std;

void recursive(vector<vector<char> > &matrix, int size, int x, int y) {
    if (size == 3) {
        for (int i = 0; i < 3; i++) {
            matrix[x][y + i] = '*';
        }
        matrix[x + 1][y] = '*';
        matrix[x + 1][y + 2] = '*';
        for (int i = 0; i < 3; i++) {
            matrix[x + 2][y + i] = '*';
        }
    } else {
        recursive(matrix, size / 3, x, y); // 왼쪽 위
        recursive(matrix, size / 3, x, y + size / 3); // 위
        recursive(matrix, size / 3, x, y + 2 * (size / 3)); // 오른쪽 위

        recursive(matrix, size / 3, x + size / 3, y); // 왼쪽
        recursive(matrix, size / 3, x + size / 3, y + 2 * (size / 3)); // 왼쪽

        recursive(matrix, size / 3, x + 2 * (size / 3), y); // 왼쪽 아래
        recursive(matrix, size / 3, x + 2 * (size / 3), y + size / 3); // 아래
        recursive(matrix, size / 3, x + 2 * (size / 3), y + 2 * (size / 3)); // 오른쪽 아래
    }

}

int main() {
    int n;
    cin >> n;

    vector<vector<char> > matrix(n);
    for (int i = 0; i < n; i++) {
        matrix[i].resize(n);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = ' ';
        }
    }

    if (n == 1) {
        cout << '*' << endl;
        return 0;
    }
    recursive(matrix, n, 0, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j];
        }
        if (i != n - 1) {
            cout << endl;
        }
    }
}