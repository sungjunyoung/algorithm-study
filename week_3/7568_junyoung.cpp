//
// Created by 성준영 on 2017. 7. 18..
//
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int> > humans;
    humans.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        humans[i].resize(2);
        cin >> humans[i][0] >> humans[i][1];
    }

    vector<int> results;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (humans[i][0] < humans[j][0] && humans[i][1] < humans[j][1]) {
                count++;
            }
        }
        results.push_back(count + 1);
    };

    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
}