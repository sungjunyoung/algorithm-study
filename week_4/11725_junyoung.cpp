//
// Created by 성준영 on 2017. 7. 26..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool com(pair<int, int> lhs, pair<int, int> rhs) {
    return lhs.second < rhs.second;
}

void bfs(vector<vector<int> > &tree) {
    vector<int> q;
    q.push_back(1);


    int n = (int) (tree.size() - 1);
    vector<bool> visits((unsigned long) (n + 1));
    for (int i = 1; i <= n; i++) {
        visits[i] = false;
    }
    visits[1] = true;

    vector<int> results; // parent, currentNode
    results.resize(n+1);

    while (!q.empty()) {
        int parentNode = q.front();
        int i;
        for (i = 0; i < tree[parentNode].size(); i++) {
            int currentNode = tree[parentNode][i];
            if (!visits[currentNode]) {
                q.push_back(currentNode);
                results[currentNode] = parentNode;
                visits[currentNode] = true;
            }
        }
        q.erase(q.begin());
    }
    for (int i = 2; i <= n; i++) {
        printf("%d\n", results[i]);
    }
}


int main() {
    vector<vector<int> > tree;

    int n;
    cin >> n;

    tree.resize((unsigned long) (n + 1));
    for (int i = 1; i < n; i++) {
        int node, toNode;
        scanf("%d%d", &node, &toNode);
        tree[node].push_back(toNode);
        tree[toNode].push_back(node);
    }

    bfs(tree);
}

// DFS 참고
// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <stdio.h>
//
// using namespace std;
//
// vector<int> rel[100001];
// int parent[100001];
//
// void DFS(int cur) {
//     for (int i: rel[cur]) {
//         if (parent[i] == -1) {
//             parent[i] = cur;
//             DFS(i);
//         }
//     }
// }
//
// int main() {
//     int n;
//     cin >> n;
//     for(int i=1;i<n;i++) {
//         int a, b;
//         scanf("%d %d", &a, &b);
//         rel[a].push_back(b);
//         rel[b].push_back(a);
//     }
//
//     memset(parent, -1, sizeof(parent));
//
//     DFS(1);
//     for (int i = 2; i <= n; i++) {
//         printf("%d\n", parent[i]);
//     }
// }