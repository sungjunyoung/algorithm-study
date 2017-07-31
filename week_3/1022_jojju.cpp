#include <iostream>
#include <math.h>
using namespace std;
int startY, startX, endY, endX;

bool isContained(int x, int y) {
    return (startX <= x && x <= endX) && (startY <= y && y <= endY);
}

int main() {
    cin >> startY >> startX >> endY >> endX;
    int rows = endY - startY + 1;
    int cols = endX - startX + 1;
    int size = rows * cols;

    int **table;
    table = new int *[rows];
    for (int i = 0; i < rows; ++i)
        table[i] = new int[cols];

    int curX = 0;
    int curY = 0;
    int num = 1;
    int range = 2;

    if (isContained(curX, curY))
    {
        table[curY - startY][curX - startX] = num;
        size--;
    }
    int log = -1;
    while (size > 0) {
        curX++;
        curY++;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < range; ++j) {
                if (i == 0) curY--;
                else if (i == 1) curX--;
                else if (i == 2) curY++;
                else curX++;
                num++;
                if (isContained(curX, curY)) {
                    table[curY - startY][curX - startX] = num;
                    size--;
                    log = max(log, (int) log10(num));
                }
            }
        }
        range += 2;
    }

    int digit;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            digit = (log - (int) log10(table[i][j]));
            for (int k = 0; k < digit; ++k)
                cout << ' ';
            cout << table[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}