#include <iostream>
using namespace std;

#define MAX_ROWS 500
#define MAX_COLS 500

int rows;
int cols;
int table[MAX_ROWS][MAX_COLS];
long long int cache[MAX_ROWS][MAX_COLS];

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

long long int recursivePath(int x, int y) {

    if (x == cols - 1 && y == rows - 1) return 1;

    if (cache[y][x] != -1) return cache[y][x];

    long long int ret = 0;
    int movedY;
    int movedX;

    for (int i = 0; i < 4; ++i) {
        movedY = y + dy[i];
        movedX = x + dx[i];
        if (movedX >= 0 && movedX < cols && movedY >= 0 && movedY < rows) {
            if ((table[movedY][movedX] < table[y][x])) {
                ret += recursivePath(movedX, movedY);
            }
        }
    }

    return cache[y][x] = ret;
}

int main() {

    scanf("%d%d", &rows, &cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            scanf("%d", &table[i][j]);
        }
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cache[i][j] = -1;
        }
    }

    printf("%lld\n", recursivePath(0, 0));

    return 0;
}