//
// Created by 성준영 on 2017. 7. 27..
//

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getLongest(vector<vector<pair<int, int> > > &tree, int startNode) {
    vector<int> q;
    q.push_back(startNode);

    vector<bool> visits;
    int n = tree.size() - 1;
    visits.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        visits[i] = false;
    }
    visits[startNode] = true;

    vector<int> lengths;
    lengths.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        lengths[i] = 0;
    }

    pair<int, int> resultPair(startNode, 0);
    while (!q.empty()) {
        for (auto i : tree[q.front()]) {
            if (!visits[i.first]) {
                lengths[i.first] = lengths[q.front()] + i.second;

                if (resultPair.second < lengths[i.first]) {
                    resultPair.first = i.first;
                    resultPair.second = lengths[i.first];
                }

                q.push_back(i.first);
                visits[i.first] = true;
            }
        }
        q.erase(q.begin());
    }

    return resultPair;
}

int main() {
    int n;
    cin >> n;

    vector<vector<pair<int, int> > > tree;
    tree.resize(n + 1);

    for (int i = 1; i < n; i++) {
        int node, toNode, length;
        scanf(" %d %d %d", &node, &toNode, &length);

        tree[node].push_back(make_pair(toNode, length));
        tree[toNode].push_back(make_pair(node, length));
    }

    cout << getLongest(tree,getLongest(tree, 1).first).second << endl;
}