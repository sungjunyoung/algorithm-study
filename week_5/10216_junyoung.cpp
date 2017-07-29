//
// Created by 성준영 on 2017. 7. 29..
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Camp {
    int num;
    int x;
    int y;
    int length;
};

int dist(Camp a, Camp b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void DFS(vector<int> &visits, vector<vector<Camp> > &relations, int start) {

    for (auto relCamp : relations[start]) {
        if (visits[relCamp.num] == 0) { // 방문하지 않았으면 들어감
            visits[relCamp.num] = 1;
            DFS(visits, relations, relCamp.num);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<Camp> camps(n + 1);

        for (int i = 1; i <= n; i++) {
            Camp c;
            c.num = i;
            scanf("%d %d %d", &c.x, &c.y, &c.length);
            camps[i] = c;
        }

        vector<vector<Camp> > relations(n + 1);
        for (int i = 1; i < n; i++) {
            for (int j = i+1; j <= n; j++) {
                int distance = dist(camps[i], camps[j]);
                // 적군 기지들이 연결된다면
                if (pow(camps[i].length + camps[j].length,2) >= distance ) {
                    relations[i].push_back(camps[j]);
                    relations[j].push_back(camps[i]);
                } else {

                }
            }
        }

        vector<int> visits(n + 1);
        int connection = 0;

        for (int i = 1; i <= n; i++) {
            if (visits[i] == 0) {
                connection++;
                DFS(visits, relations, i);
            }
        }
        cout << connection << endl;
    }
}