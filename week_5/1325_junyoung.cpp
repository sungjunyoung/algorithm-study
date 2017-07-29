//
// Created by 성준영 on 2017. 7. 29..
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool com (pair<int, int> a, pair<int, int> b){
    return a.first < b.first;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > relations(n + 1);
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        relations[b].push_back(a);
    }

    vector<pair<int, int> > results;
    int max = 0;
    for (int i = 1; i <= n; i++) {
        // BFS
        queue<int> q;
        vector<int> visits(n + 1);
        int counter = 0;

        q.push(i);
        visits[i] = 1;

        while (!q.empty()) {
            int cur = q.front();

            for (auto next : relations[cur]) {
                if (visits[next] == 0) {
                    q.push(next);
                    visits[next] = 1;
                    counter++;
                    if (counter > max) {
                        max = counter;
                    }
                }
            }

            q.pop();
        }

        results.push_back(make_pair(i, counter));
    }

    sort(results.begin(), results.end(), com);

    for(auto res: results){
        if(res.second == max){
            printf("%d ", res.first);
        }
    }

}