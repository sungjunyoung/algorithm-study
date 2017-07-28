//
// Created by 성준영 on 2017. 7. 28..
//

#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > getOut((unsigned long) (n + 1));
    vector<vector<int> > getIn((unsigned long) (n + 1));
    vector<int> degree((unsigned long) (n + 1));
    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf(" %d %d", &a, &b);
        getOut[a].push_back(b);
        getIn[b].push_back(a);
        degree[b]++;
    }

    // 위상정렬로 줄세우기

    vector<int> queue;
    // 돌면서 degree 가 0 인 정점을 큐에 넣음
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            queue.push_back(i);
        }
    }

    vector<int> result((unsigned long) (n + 1));
    for (int i = 1; i <= n; i++) {
        int current = queue.front();
        queue.erase(queue.begin());
        result[i] = current;

        for(int out: getOut[current]){
            for(int in: getIn[out]){
                if(in == current){
                    degree[out]--;
                    break;
                }
            }

            if(degree[out] == 0){
                queue.push_back(out);
            }
        }
    }


    for (int i = 1; i <= n; i++) {
        if (i == n) {
            printf("%d", result[i]);
        } else {
            printf("%d ", result[i]);
        }
    }
}