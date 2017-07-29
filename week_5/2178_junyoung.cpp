//
// Created by 성준영 on 2017. 7. 29..
//


#include <iostream>
#include <queue>

using namespace std;

int moveN[] = {0, -1, 1, 0};
int moveM[] = {-1, 0, 0, 1};

int main() {
    int matrix[101][101];
    int visits[101][101];
    int count[101][101];
    queue<pair<int, int> > q;
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &matrix[i][j]);
        }
    }

    q.push(make_pair(1, 1));
    visits[1][1] = 1;
    count[1][1] = 1;
    while (!q.empty()) {
        pair<int, int> curIndex = q.front();

        for (int i = 0; i < 4; i++) {
            int moveToN = curIndex.first + moveN[i];
            int moveToM = curIndex.second + moveM[i];
            if (moveToN > 0 && moveToN <= n && moveToM > 0 && moveToM <= m) {
                if (visits[moveToN][moveToM] == 0) {
                    if(matrix[moveToN][moveToM] == 1){
                        q.push(make_pair(moveToN, moveToM));
                        visits[moveToN][moveToM] = 1;
                        count[moveToN][moveToM] = count[curIndex.first][curIndex.second] + 1;
                    }
                }
            }
        }

        q.pop();
    }

    cout << count[n][m];

}