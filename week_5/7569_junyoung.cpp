//
// Created by 성준영 on 2017. 7. 29..
//

#include <iostream>
#include <queue>

using namespace std;

int moveFirst[] = {0, -1, 1, 0, 0, 0};
int moveSecond[] = {-1, 0, 0, 1, 0, 0};
int moveThird[] = {0, 0, 0, 0, 1, -1};

struct TomatoIndex {
    int M;
    int N;
    int H;
};

int box[101][101][101];
int counter[101][101][101];
int visits[101][101][101];


int main() {
    int m, n, h; // 가로 세로 높이

    cin >> m >> n >> h;

    queue<TomatoIndex> q;

    // 위아래
    for (int i = 1; i <= h; i++) {
        // 세로
        for (int j = 1; j <= n; j++) {
            // 가로
            for (int k = 1; k <= m; k++) {
                cin >> box[i][j][k];
                if (box[i][j][k] == 1) {
                    TomatoIndex t;
                    t.H = i;
                    t.N = j;
                    t.M = k;
                    q.push(t);
                    visits[i][j][k] = 1;
                }
            }
        }
    }

    while (!q.empty()) {
        TomatoIndex curIndex = q.front();

        for (int i = 0; i < 6; i++) { //왼 위 아 오 상 하
            int moveToM = curIndex.M + moveFirst[i];
            int moveToN = curIndex.N + moveSecond[i];
            int moveToH = curIndex.H + moveThird[i];

            // 범위를 넘거나 이미 방문했으면 X
            if (moveToM > 0 && moveToM <= m && moveToN > 0 && moveToN <= n &&
                moveToH > 0 && moveToH <= h) {
                if (visits[moveToH][moveToN][moveToM] == 0 && box[moveToH][moveToN][moveToM] != -1) {
                    TomatoIndex t;
                    t.H = moveToH;
                    t.N = moveToN;
                    t.M = moveToM;
                    q.push(t);

                    // 얼마나 갔는지 저장
                    counter[moveToH][moveToN][moveToM] =
                            counter[curIndex.H][curIndex.N][curIndex.M] + 1;
                    // 방문 저장
                    visits[moveToH][moveToN][moveToM] = 1;
                    // 토마토 익음
                    box[moveToH][moveToN][moveToM] = 1;
                }
            }
        }
        q.pop();
    }


    int result = 0;
    bool check = true;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= m; k++) {
                if(result < counter[i][j][k]){
                    result = counter[i][j][k];
                }
                if(box[i][j][k] == 0){
                    check = false;
                }
            }
        }
    }

    if(check){
        cout << result;
    } else {
        cout << -1;
    }
}