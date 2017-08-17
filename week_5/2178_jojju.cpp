#include <iostream>
#include <queue>

using namespace std;

#define MAX 100

int numCol, numRow;
int table[MAX + 1][MAX + 1];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int ret;

struct point {
    int x;
    int y;

    point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

queue<point> myQueue;

void bfs() {

    if (table[numRow - 1][numCol - 1] == 2) {
        cout << ret + 1 << endl;
        return;
    }
    ret++;
    int movedX, movedY;
    int currentSize = (int) myQueue.size();
    while (currentSize--) {
        for (int j = 0; j < 4; ++j) {
            movedX = myQueue.front().x + dx[j];
            movedY = myQueue.front().y + dy[j];
            if (movedX >= 0 && movedX < numCol && movedY >= 0 && movedY < numRow) {
                if (table[movedY][movedX] == 1) {
                    table[movedY][movedX] = 2;
                    point temp(movedX, movedY);
                    myQueue.push(temp);
                }
            }
        }
        myQueue.pop();
    }
    bfs();
}

int main() {
    cin >> numRow >> numCol;
    char input;
    for (int i = 0; i < numRow; ++i) {
        for (int j = 0; j < numCol; ++j) {
            cin >> input;
            table[i][j] = input - '0';
        }
    }
    point temp(0, 0);
    myQueue.push(temp);
    table[0][0] = 2;

    bfs();

    return 0;
}