#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
int main() {
	int n; //포도잔 개수
	int g[10001]; //포도주 양
	int dp[10001][3];
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> g[i];
	}

	//dp arr 초기화
	dp[1][0] = 0;
	dp[1][1] = g[1];
	dp[1][2] = g[1];
	int tmp = 0;
	//dp
	for (int i = 2; i <= n; i++) {
		tmp = std::max(dp[i - 1][0], dp[i - 1][1]);
		dp[i][0] = std::max(tmp, dp[i - 1][2]);
		dp[i][1] = dp[i - 1][0] + g[i];
		dp[i][2] = dp[i - 1][1] + g[i];
	}
	//답 출력
	int sol = std::max(dp[n][0], dp[n][1]);
	cout << std::max(sol, dp[n][2]);
	return 0;
}