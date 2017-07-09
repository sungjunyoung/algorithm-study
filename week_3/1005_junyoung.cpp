#include <iostream>
#include <vector>

using namespace std;

int n, k;
int w;


int getCost(int *memo,vector<long long int> &D, vector<int> &buildings, vector<vector<int> > &relations, int currentBuilding) {

    if(memo[currentBuilding] != 0){
        return memo[currentBuilding];
    }

    if (w == currentBuilding && D[w] != -1) {
        return D[w];
    }

    vector<int> fromBuildings;
    for (int i = 0; i <= n; i++) {
        if (relations[i][currentBuilding] != 0) {
            fromBuildings.push_back(i);
        }
    }

    int currentCost = 0;
    if (fromBuildings.size() != 0) {
        for (int i = 0; i < fromBuildings.size(); i++) {
            if (D[fromBuildings[i]] == -1) {
                getCost(memo,D, buildings, relations, fromBuildings[i]);
            }
            if (D[fromBuildings[i]] > currentCost) {
                currentCost = D[fromBuildings[i]];
            }
        }
        currentCost += buildings[currentBuilding];
    } else {
        currentCost = buildings[0];
    }

    D[currentBuilding] = currentCost;
    memo[currentBuilding] = currentCost;
    if (w == currentBuilding) {
        return D[w];
    }

    vector<int> toBuildings;

    for (int i = 0; i <= n; i++) {
        if (relations[currentBuilding][i] != 0) {
            toBuildings.push_back(i);
        }
    }

    for (int i = 0; i < toBuildings.size(); i++) {
        getCost(memo, D, buildings, relations, toBuildings[i]);
    }

}


int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n >> k;

        vector<int> buildings;
        buildings.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> buildings[i];
        }

        // 관계그래프 생성
        vector<vector<int> > relations;
        relations.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            relations[i].resize(n + 1);
        }
        // 관계그래프 초기화
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                relations[i][j] = 0;
            }
        }

        for (int i = 1; i <= k; i++) {
            int from, to;
            cin >> from >> to;
            relations[from][to] = 1;
        }

        cin >> w;

        // DP Result 테이블
        vector<long long int> D;
        D.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            D[i] = -1;
        }

        // from 이 없는 노드 검색
        vector<int> rootBuildings;
        int flag = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (relations[j][i] == 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                rootBuildings.push_back(i);
            }
            flag = true;
        }

        for (int i = 0; i < rootBuildings.size(); i++) {
            D[rootBuildings[i]] = buildings[rootBuildings[i]];
        }

        // 0 번째 빌딩이 있다고 가정
        for (int i = 0; i < rootBuildings.size(); i++) {
            relations[0][rootBuildings[i]] = 1;
        }
        buildings[0] = 0;
        D[0] = 0;

        int *memo = new int[n+1];
        for (int i = 0; i < n+1; i++) {
            memo[i] = 0;
        };

        getCost(memo, D, buildings, relations, 0);

        cout << D[w] << endl;

    }
}
