#include <iostream>

using namespace std;
#define MAX 6600
char table[MAX + 1][MAX + 1];
int N;

void recursive(int y, int x, int size) {
    if (size == 1) {
        table[y][x] = '*';
        return;
    }
    size /= 3;
    int d[] = {0, size, size * 2};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == 1 && j == 1)
                continue;
            recursive(y + d[i], x + d[j], size);
        }
    }

}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            table[i][j] = ' ';

    recursive(0, 0, N);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << table[i][j];
        }
        cout << endl;
    }

    return 0;
}
