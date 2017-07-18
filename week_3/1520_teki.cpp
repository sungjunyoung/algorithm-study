#include <iostream>
using std::cin;
using std::cout;

int map[501][501];
int dp[501][501];

int d_x[] = { 1,0,0,-1 };
int d_y[] = { 0,1,-1,0 };

int n;
int m;

int sol(int x, int y) {
	//목적지에 가면 1 반환
	if (x == n && y == m)
		return 1;
	//처음 계산하는 곳이면 0으로
	if (dp[x][y] == -1)
		dp[x][y] = 0;
	//4방향 점검
	for (int i = 0; i <= 3; i++) {
		int n_x = x + d_x[i];
		int n_y = y + d_y[i];
		//배열 밖이면 넘기고
		if (n_x < 1 || n_x > n || n_y < 1 || n_y > m)
			continue;
		//내리막이면
		if (map[x][y] > map[n_x][n_y]) {
			//점검하는 곳이 처음가는 곳이면 재귀
			if (dp[n_x][n_y] == -1) {
				dp[x][y] += sol(n_x, n_y);
			}
			//가봤던 곳이면 더해줌
			else {
				dp[x][y] += dp[n_x][n_y];
			}
		}
	}
	return dp[x][y];
}



int main() {
	//입력
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
	cout << sol(1, 1);
	return 0;
}