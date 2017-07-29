//
// Created by 성준영 on 2017. 7. 29..
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int moveX[] = {0, -1, 1, 0};
int moveY[] = {-1, 0, 0, 1};

int main() {
    int n;
    cin >> n;

    vector<vector<int> > map(static_cast<unsigned long>(n + 1));
    for (int i = 1; i <= n; i++) {
        map[i].resize(static_cast<unsigned long>(n + 1));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%1d",&map[i][j]);
        }
    }

    // 단지번호
    vector<vector<int> > num(static_cast<unsigned long>(n + 1));
    for (int i = 1; i <= n; i++) {
        num[i].resize(static_cast<unsigned long>(n + 1));
    }

    int numCount = 0;

    // 모든 집을 순회하면서 찾기
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 집이 있고, 아직 단지번호가 매겨지지 않은 집들에 대해서
            if (map[i][j] == 1 && num[i][j] == 0) {
                numCount++;
                num[i][j] = numCount;

                // BFS
                queue<pair<int, int> > q;
                q.push(make_pair(i, j));
                while (!q.empty()) {
                    pair<int, int> curIndex = q.front();

                    for (int i = 0; i < 4; i++) {
                        int moveToX = curIndex.first + moveX[i];
                        int moveToY = curIndex.second + moveY[i];

                        if (moveToX > 0 && moveToX <= n && moveToY > 0 && moveToY <= n) {
                            if (num[moveToX][moveToY] == 0 && map[moveToX][moveToY] == 1) {
                                q.push(make_pair(moveToX, moveToY));
                                num[moveToX][moveToY] = numCount;
                            }
                        }
                    }
                    q.pop();
                }

            }
        }
    }



    vector<int> results(numCount + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (num[i][j] != 0) {
                results[num[i][j]]++;
            }
        }
    }

    sort(results.begin(), results.end());
    cout << numCount << endl;
    for (int i = 1; i < numCount; i++) {
        cout << results[i] << endl;
    }
    cout << results[numCount];
}