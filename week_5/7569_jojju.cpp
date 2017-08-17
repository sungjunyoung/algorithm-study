#include <iostream>
#include <vector>

using namespace std;

#define MAX 100

int numCol, numRow, height, numOfRemainTomato;
int table[MAX + 1][MAX + 1][MAX + 1];
int dx[] = {-1, 0, 0, 1, 0, 0};
int dy[] = {0, -1, 1, 0, 0, 0};
int dh[] = {0, 0, 0, 0, 1, -1};
int ret = -1;

struct point {
    int x;
    int y;
    int h;

    point() {
        x = 0;
        y = 0;
        h = 0;
    }
};

void bfs(vector<point> ripedTomato) {

    if (numOfRemainTomato <= 0) return;
    if (numOfRemainTomato > 0 && ripedTomato.size() == 0) {
        ret = -2;
        return;
    }
    ret++;
    int movedX;
    int movedY;
    int movedH;
    vector<point> newRipedTomato;
    point point1;

    for (int i = 0; i < ripedTomato.size(); ++i) {
        for (int j = 0; j < 6; ++j) {
            movedX = ripedTomato[i].x + dx[j];
            movedY = ripedTomato[i].y + dy[j];
            movedH = ripedTomato[i].h + dh[j];

            if (movedX >= 0 && movedX < numCol
                && movedY >= 0 && movedY < numRow
                && movedH >= 0 && movedH < height) {
                if (table[movedY][movedX][movedH] == 0) {
                    table[movedY][movedX][movedH] = 1;
                    point1.x = movedX;
                    point1.y = movedY;
                    point1.h = movedH;
                    newRipedTomato.push_back(point1);
                    numOfRemainTomato--;
                }

            }
        }
    }

    ripedTomato.clear();
    bfs(newRipedTomato);
}

int main() {
    cin >> numCol >> numRow >> height;

    vector<point> ripedTomato;
    point point1;
    bool neverRiped = true;
    for (int k = 0; k < height; ++k) {
        for (int i = 0; i < numRow; ++i) {
            for (int j = 0; j < numCol; ++j) {
                cin >> table[i][j][k];
                if (table[i][j][k] == 0)
                    numOfRemainTomato++;
                if (table[i][j][k] == 1) {
                    point1.x = j;
                    point1.y = i;
                    point1.h = k;
                    ripedTomato.push_back(point1);
                    neverRiped = false;
                }
            }

        }
    }
    if (neverRiped)
        cout << -1 << endl;
    else {
        bfs(ripedTomato);
        cout << ret + 1 << endl;
    }
    return 0;
}