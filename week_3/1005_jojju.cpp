#include <iostream>
#include <vector>

using namespace std;
int N, K, W;

int recursive(int *buildings, int **directionTable, int *cache, vector<int> &startPoints, int curPosition) {
    bool arrived = false;
    for (int i = 0; i < startPoints.size(); ++i) {
        if (curPosition == startPoints[i]) {
            arrived = true;
            break;
        }
    }
    if (arrived) return buildings[curPosition];
    if (cache[curPosition]) return cache[curPosition];

    int ret = -1;
    for (int i = 1; i <= N; ++i)
        if (directionTable[i][curPosition] == 1)
            ret = max(ret, recursive(buildings, directionTable, cache, startPoints, i) + buildings[curPosition]);

    return cache[curPosition] = ret;
}

int main() {
    int testCase;
    cin >> testCase;

    while (testCase--) {
        cin >> N >> K;
        //setting
        int *buildings = new int[N + 1];

        int **directionTable = NULL;
        directionTable = new int *[N + 1];
        for (int i = 0; i < N + 1; ++i)
            directionTable[i] = new int[N + 1];

        int *cache = new int[N + 1];

        //input
        for (int i = 1; i <= N; ++i)
            cin >> buildings[i];

        int start, end;
        for (int i = 0; i < K; ++i) {
            cin >> start >> end;
            directionTable[start][end] = 1;
        }
        cin >> W;

        //scan start points
        vector<int> startPoints;
        bool isStartPoint;
        for (int j = 1; j <= N; ++j) {
            isStartPoint = true;
            for (int i = 1; i <= N; ++i)
                if (directionTable[i][j] == 1)
                    isStartPoint = false;

            if (isStartPoint) startPoints.push_back(j);
        }

        cout << recursive(buildings, directionTable, cache, startPoints, W) << endl;
    }

    return 0;
}