//
// Created by 성준영 on 2017. 7. 28..
//

#include <iostream>
#include <vector>

using namespace std;

void changeGraph(int from, int to, vector<vector<pair<int, bool> > > &graph, vector<int> &degree) {
    bool flag = false;
    for (auto &i : graph[from]) {
        if (i.first == to) {
            flag = true;
            i.second = false;
            degree[from]--;
            break;
        }
    }

    if (flag) {
        graph[to].push_back(make_pair(from, true));
        degree[to]++;
        return;
    } else {
        for (auto &i : graph[to]) {
            if (i.first == from) {
                i.second = false;
                degree[to]--;
                break;
            }
        }
        graph[from].push_back(make_pair(to, true));
        degree[from]++;
        return;
    }
}

vector<int> result;
string ans;

void getResult(vector<vector<pair<int, bool> > > &graph, vector<int> &degree) {
    vector<int> queue;
    int n = (int) (degree.size() - 1);

    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) queue.push_back(i);
    }

    vector<int> visits((unsigned long) (n + 1));
    for (int i = 1; i <= n; i++) {
        visits[i] = false;
    }
    for (int i = 1; i <= n; i++) {

        if (queue.size() == 0) {
            ans = "IMPOSSIBLE";
            return;
        }

        int current = queue.front();
        visits[current] = true;
        result.push_back(current);
        queue.erase(queue.begin());

        for (int j = 1; j <= n; j++) {
            for (auto &next : graph[j]) {
                if (next.first == current) {
                    next.second = false;
                    degree[j]--;
                    break;
                }
            }

            if (degree[j] == 0 && !visits[j]) {
                queue.push_back(j);
            }
        }

    }

    if (result.size() == n) {
        return;
    } else {
        ans = "?";
        return;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {

        result.clear();
        ans = "";

        int n;
        cin >> n;
        vector<int> teams;
        teams.resize((unsigned long) (n + 1));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &teams[i]);
        }

        vector<vector<pair<int, bool> > > graph((unsigned long) (n + 1));
        vector<int> degree((unsigned long) (n + 1));
        for (int i = 1; i <= n; i++) {
            degree[i] = 0;
        }

        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                graph[teams[j]].push_back(make_pair(teams[i], true));
                degree[teams[j]]++;
            }
        }


        int m;
        cin >> m;
        bool flag = true;
        for (int i = 1; i <= m; i++) {
            int from, to;
            scanf(" %d %d", &from, &to);
            changeGraph(from, to, graph, degree);
        }

        getResult(graph, degree);

        if (ans == "?") {
            printf("?\n");
        } else if (ans == "IMPOSSIBLE") {
            printf("IMPOSSIBLE\n");
        } else {
            for (int i = 0; i < n; i++) {
                if (i == n - 1) {
                    printf("%d\n", result[i]);
                } else {
                    printf("%d ", result[i]);
                }
            }
        }
    }
}