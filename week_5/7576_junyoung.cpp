//
// Created by 성준영 on 2017. 7. 29..
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int moveFirst[] = {0, -1, 1, 0};
int moveSecond[] = {-1, 0, 0, 1};

int main() {
    int m, n;
    cin >> m >> n;

    vector<vector<int> > box((unsigned long) (n + 1));
    vector<vector<int> > count((unsigned long) (n + 1));
    for (int i = 1; i <= n; i++) {
        box[i].resize((unsigned long) (m + 1));
        count[i].resize((unsigned long) (m + 1));
    }

    // 큐
    queue<pair<int, int> > rippedIndexQueue;

    // 방문
    vector<vector<int> > visits((unsigned long) (n + 1));
    for (int i = 1; i <= n; i++) {
        visits[i].resize((unsigned long) (m + 1));
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> box[i][j];
            if (box[i][j] == 1) {
                rippedIndexQueue.push(make_pair(i, j));
                visits[i][j] = 1;
            }
        }
    }

    while (!rippedIndexQueue.empty()) {
        pair<int, int> currentIndex = rippedIndexQueue.front();

        // 네 방향 bfs
        for (int i = 0; i < 4; i++) {
            int toFirst = currentIndex.first + moveFirst[i];
            int toSecond = currentIndex.second + moveSecond[i];

            // 방문 했거나, 인덱스를 벗어나면 X
            if (toFirst > 0 && toFirst <= n && toSecond > 0 && toSecond <= m && box[toFirst][toSecond] != -1) {
                if (visits[toFirst][toSecond] == 0) {
                    rippedIndexQueue.push(make_pair(toFirst, toSecond));
                    box[toFirst][toSecond] = 1;
                    count[toFirst][toSecond] = count[currentIndex.first][currentIndex.second] + 1;
                    visits[toFirst][toSecond] = 1;
                }
            }
        }
        rippedIndexQueue.pop();
    }

    int result = 0;
    int check = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if(count[i][j] > result){
                result = count[i][j];
            }
            if(box[i][j] == 0){
                check = false;
            }
        }
    }

    if(!check){
        cout << -1;
    } else {
        cout << result;
    }
}