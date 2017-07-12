#include <iostream>
#include <vector>

using namespace std;

int m, n;

int matrix[502][502];

long long int dfs(long long int D[502][502], int x, int y) {

    if (x < 1 || x > n) {
        return 0;
    }
    if (y < 1 || y > m) {
        return 0;
    }

    if (D[y][x] != -1) {
        return D[y][x];
    }

    long long int result = 0;
    if (matrix[y][x] > matrix[y - 1][x]) { //위
        result += dfs(D, x, y - 1);
    }

    if (matrix[y][x] > matrix[y][x + 1]) {//오른쪽
        result += dfs(D, x + 1, y);
    }

    if (matrix[y][x] > matrix[y + 1][x]) { //아래
        result += dfs(D, x, y + 1);
    }

    if (matrix[y][x] > matrix[y][x - 1]) {//왼쪽
        result += dfs(D, x - 1, y);
    }

    D[y][x] = result;
    return result;

}

int main() {
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    long long int D[502][502];

    for (int i = 0; i < 502; i++) {
        for (int j = 0; j < 502; j++) {
            D[i][j] = -1;
        }
    }

    D[m][n] = 1;

    dfs(D, 1, 1);


    cout << D[1][1] << endl;

}
