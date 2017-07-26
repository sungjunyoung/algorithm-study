//
// Created by 성준영 on 2017. 7. 26..
//

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> getLongestNode(vector<vector<pair<int, int> > > &tree, int startNode) {
    vector<int> q;
    q.push_back(startNode);
    int v = (int) (tree.size() - 1);
    vector<int> visits((unsigned long) v + 1);
    vector<int> lengths((unsigned long) v + 1);
    for (int i = 1; i <= v; i++) {
        visits[i] = -1;
        lengths[i] = 0;
    }
    visits[startNode] = 1;


    while (!q.empty()) {
        for (int i = 1; i <= tree[q.front()].size() - 1; i++) {
            int currentNode = tree[q.front()][i].first;
            if (visits[currentNode] == -1) {
                q.push_back(currentNode);
                visits[currentNode] = 1;

                lengths[currentNode] = lengths[q.front()] + tree[q.front()][i].second;
            }

        }
        q.erase(q.begin());
    }

    pair<int, int> res(startNode, lengths[startNode]);
    for (int i = 1; i <= lengths.size() - 1; i++) {
        if(res.second < lengths[i]){
            res.first = i;
            res.second = lengths[i];
        }
    }
    return res;
}

int main() {
    int v;
    cin >> v;

    vector<vector<pair<int, int> > > tree;
    tree.resize(v + 1);

    int nodeNum;
    for (int i = 1; i <= v; i++) {
        cin >> nodeNum;

        int toNode;
        int length;
        while (1) {
            cin >> toNode;
            if (toNode == -1) {
                break;
            }
            cin >> length;

            tree[nodeNum].push_back(make_pair(toNode, length));
            tree[toNode].push_back(make_pair(nodeNum, length));
        }
    }

    int start = getLongestNode(tree, 1).first;
    int result = getLongestNode(tree, start).second;
    cout << result << endl;
}
