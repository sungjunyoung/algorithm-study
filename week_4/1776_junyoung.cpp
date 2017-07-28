//
// Created by 성준영 on 2017. 7. 28..
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> getResult(vector<vector<int> > relation, vector<int> degree) {

    int n = (int) (degree.size() - 1);
    // 정렬되어 들어가야하므로 우선순위 큐
    priority_queue<int, vector<int>, greater<int> > q;

    // 1. 큐에 degree 가 0 인거를 먼저 넣는다.
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }
    // 2. 위상정렬
    vector<int> result;
    while (!q.empty()) {
        int current = q.top();
        q.pop();
        result.push_back(current);

        int size = (int) relation[current].size();
        for (int i = 0; i < size; i++) {
            degree[relation[current][i]]--;

            if (degree[relation[current][i]] == 0) {
                q.push(relation[current][i]);
            }
        }
    }

    return result;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > relation((unsigned long) (n + 1));
    vector<int> degree((unsigned long) (n + 1));

    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        relation[a].push_back(b);
        degree[b]++;
    }

    vector<int> result = getResult(relation, degree);
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            printf("%d", result[i]);
        } else {
            printf("%d ", result[i]);
        }
    }
}