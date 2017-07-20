#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;
    vector<vector<int> > A(n);
    for (int i = 0; i < n; i++) {
        A[i].resize(m);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    int m2, k;
    cin >> m2 >> k;
    vector<vector<int> > B(m);
    for (int i = 0; i < m; i++) {
        B[i].resize(k);
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> B[i][j];
        }
    }

    vector<vector<int> > result(n);
    for (int i = 0; i < n; i++) {
        result[i].resize(k);
    }

    for (int i = 0; i < n; i++) { // A 세로만큼
        for (int j = 0; j < k; j++) { // B 세로만큼
            int sum = 0;
            for (int x = 0; x < m; x++) {
                sum += A[i][x] * B[x][j];
            }
            result[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cout << result[i][j] << " ";
        }
        if (i != n - 1) {
            cout << endl;
        }
    }
}

