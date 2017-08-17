#include <iostream>
#include <vector>

using namespace std;

#define MAX 1000

int numCol, numRow;
int table[MAX + 1][MAX + 1];
int numOfRemainTomato;
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};
int ret = -1;

struct point {
    int x;
    int y;

    point() {
        x = 0;
        y = 0;
    }
};

void bfs(vector<point> &ripedTomato) {

    if (numOfRemainTomato <= 0) return;
    if(numOfRemainTomato > 0 && ripedTomato.size() == 0)
    {
        ret = -2;
        return;
    }
    ret++;
    int movedX;
    int movedY;
    vector<point> newripedTomato;
    point point1;

    for (int i = 0; i < ripedTomato.size(); ++i) {
        for (int j = 0; j < 4; ++j) {
            movedX = ripedTomato[i].x + dx[j];
            movedY = ripedTomato[i].y + dy[j];
            if (movedX >= 0 && movedX < numCol && movedY >= 0 && movedY < numRow) {
                if (table[movedY][movedX] == 0) {
                    table[movedY][movedX] = 1;
                    point1.x = movedX;
                    point1.y = movedY;
                    newripedTomato.push_back(point1);
                    numOfRemainTomato--;
                }

            }
        }
    }

    ripedTomato.clear();
    bfs(newripedTomato);
}

int main() {
    cin >> numCol >> numRow;

    vector<point> ripedTomato;
    point point1;
    bool neverRiped = true;
    for (int i = 0; i < numRow; ++i) {
        for (int j = 0; j < numCol; ++j) {
            cin >> table[i][j];
            if (table[i][j] == 0)
                numOfRemainTomato++;
            if (table[i][j] == 1) {
                point1.x = j;
                point1.y = i;
                ripedTomato.push_back(point1);
                neverRiped = false;
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