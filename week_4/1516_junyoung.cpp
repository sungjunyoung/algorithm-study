//
// Created by 성준영 on 2017. 7. 28..
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> getResult(vector<int> buildLength,
                      vector<vector<int> > nextBuild,
                      vector<vector<int> > preBuild) {
    // 1. 들어오는 선이 없는 것들을 큐에 넣는다.
    vector<int> q;
    int n = (int) (buildLength.size() - 1);
    for (int i = 1; i <= n; i++) {
        if (preBuild[i].size() == 0) {
            q.push_back(i);
        }
    }

    // 2. 위상정렬
    vector<int> result((unsigned long) (n + 1));
    for (int i = 0; i < q.size(); i++) {
        result[q[i]] = buildLength[q[i]];
    }

    while (!q.empty()) {
        int current = q.front();

        q.erase(q.begin());

        for (int j = 0; j < nextBuild[current].size(); j++) {
            int next = nextBuild[current][j];

            for (int k = 0; k < preBuild[next].size(); k++) {
                if (preBuild[next][k] == current) {
                    preBuild[next].erase(preBuild[next].begin() + k);
                }

            }
            if (result[next] < result[current] + buildLength[next]) {
                result[next] = result[current] + buildLength[next];
            }

            if (preBuild[next].size() == 0) {
                q.push_back(next);
            }
        }

    }

    return result;
}

int main() {
    int n;
    cin >> n;


    vector<int> buildLength((unsigned long) (n + 1));
    vector<vector<int> > nextBuild((unsigned long) (n + 1));
    vector<vector<int> > preBuild((unsigned long) (n + 1));

    // 입력
    for (int current = 1; current <= n; current++) {
        int length;
        cin >> length;
        buildLength[current] = length;
        int pre;
        while (1) {
            scanf("%d", &pre);
            if (pre == -1) {
                break;
            }
            preBuild[current].push_back(pre);
            nextBuild[pre].push_back(current);
        }
    }

    vector<int> result = getResult(buildLength, nextBuild, preBuild);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", result[i]);
    }

}