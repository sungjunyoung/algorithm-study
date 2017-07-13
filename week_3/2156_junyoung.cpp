#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[10001];
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }

    int D[10001][2] = {0,};

    D[1][1] = a[1];
    D[1][0] = 0;
    D[2][0] = a[1];
    D[2][1] = a[1] + a[2];

    for (int i = 3; i <= n; i++) {
        D[i][0] = max(D[i - 1][0], D[i - 1][1]);
        D[i][1] = max(a[i] + a[i - 1] + D[i - 2][0], a[i] + D[i - 2][1]);
    }

    cout << max(D[n][0], D[n][1]) << endl;
}
