//
// Created by 성준영 on 2017. 7. 29..
//

#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int> > &network, vector<int> &visit, int start) {
    visit[start] = 1;

    for (int i = 1; i < network[start].size(); i++) {
        if (network[start][i] == 1 && visit[i] == 0) {
            DFS(network, visit, i);
        }
    }
}

int main() {
    int n, m; // 컴퓨터 수, 네트워크 컴퓨터 쌍 수
    cin >> n >> m;
    vector<vector<int> > network(static_cast<unsigned long>(n + 1));
    for (int i = 1; i <= n; i++) {
        network[i].resize(static_cast<unsigned long>(n + 1));
    }
    vector<int> visit(static_cast<unsigned long>(n + 1));

    for (int i = 1; i <= m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);

        network[a][b] = 1;
        network[b][a] = 1;
    }

    DFS(network, visit, 1);
    int result = 0;
    for (int i = 2; i <= n; i++) {
        if(visit[i] == 1){
            result ++ ;
        }
    }
    cout << result;
}