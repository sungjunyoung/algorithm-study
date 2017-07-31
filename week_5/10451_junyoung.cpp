//
// Created by 성준영 on 2017. 7. 29..
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int> > graph(n + 1);
        for (int i = 1; i <= n; i++) {
            int a;
            scanf("%d", &a);
            graph[i].push_back(a);
        }


        int count = 0;
        vector<int> visits(n + 1);
        for (int i = 1; i <= n; i++) {

            // 모든 정점에 대해서 bfs
            if (visits[i] == 0) {
                queue<int> q;
                q.push(i);

                while (!q.empty()) {
                    int cur = q.front();

                    for (auto next : graph[cur]) {
                        if (visits[next] == 0) {
                            q.push(next);
                            visits[next] = 1;
                        }
                    }
                    q.pop();
                }

                count++;
            }
        }

        cout << count << endl;
    }
}