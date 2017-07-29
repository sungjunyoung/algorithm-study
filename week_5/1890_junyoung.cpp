//
// Created by 성준영 on 2017. 7. 29..
//

#include <iostream>
#include <vector>

using namespace std;

long long DFS(vector<vector<int> > &map, vector<vector<long long> > &D, int x, int y) {
    int n = map.size() - 1;
    int moveRight = y + map[x][y];
    int moveDown = x + map[x][y];

    if (x == n && y == n) { // 기저
        return D[n][n];
    }
    if(map[x][y] == 0){
        return 0;
    }
    if (D[x][y] != -1) {
        return D[x][y];
    }

    long long right = 0, left = 0;
    if (moveRight > 0 && moveRight <= n) {
        right = DFS(map, D, x, moveRight);
    }
    if (moveDown > 0 && moveDown <= n) {
        left = DFS(map, D, moveDown, y);
    }


    D[x][y] = right + left;

//    for (int i = 1; i <= n; i++) {
//        for (int j = 1; j <= n; j++) {
//            cout << D[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    return D[x][y];
}

int main() {

    int n;
    cin >> n;

    // 맵
    vector<vector<int> > map(n + 1);
    for (int i = 1; i <= n; i++) {
        map[i].resize(n + 1);
    }

    // 입력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
        }
    }

    // DP 용 D 초기화 (-1)
    vector<vector<long long> > D(n + 1);
    for (int i = 1; i <= n; i++) {
        D[i].resize(n + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            D[i][j] = -1;
        }
    }

    D[n][n] = 1;
    cout << DFS(map, D, 1, 1);
}