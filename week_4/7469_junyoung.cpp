#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    int index;
    int value;
};

struct valueOperation {
    inline bool operator()(const node &node1, const node &node2) {
        return (node1.value < node2.value);
    }
};

int getResult(vector<node> a, int i, int j, int k) {
    int count = 0;
    for (int x = 0; x < a.size(); x++) {

        if (a[x].index < i || a[x].index > j) {
            continue;
        } else {
            count++;
            if(count == k){
                return a[x].value;
            }
        }
    }
}

int main() {
    int n, m;
    vector<node> a;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int temp;
        scanf("%d", &temp);
        struct node tempNode = {i, temp};
        a.push_back(tempNode);
    }

    sort(a.begin(), a.end(), valueOperation());

    for (int x = 1; x <= m; x++) {
        int i, j, k;
        scanf("%d%d%d", &i, &j, &k);
        cout << getResult(a, i, j, k) << endl;
    }

}

