//
// Created by MAC on 2017. 7. 13..
//

#include <iostream>
#include <algorithm>

using namespace std;
int DP[1001];
int M[1001][1001], D[1001];

int solve(int W, int N) {
    if (DP[W] > 0) return DP[W];

    int result = 0;
    for (int i = 1; i <= N; i++) {
        if (M[W][i] == 1) {
            result = max(result, solve(i, N));
        }
    }
    return DP[W] = result + D[W];
}

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, K, W;
        for (int j = 0; j < 1001; j++)
            D[j] = DP[j] = 0;
        for (int j = 0; j < 1001; j++) {
            for (int k = 0; k < 1001; k++) {
                M[j][k] = 0;
            }
        }

        cin>>N>>K;
        for (int j = 1; j <= N; j++)
            cin>>D[j];
        for (int j = 0; j < K; j++) {
            int x, y;
            cin>>x>>y;
            M[y][x] = 1;
        }
        cin>>W;
        cout<<solve(W, N)<<endl;
    }
    return 0;
}