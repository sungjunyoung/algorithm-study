#include <iostream>
using std::cin;
using std::cout;
int main() {
	int n; //동전 종류
	int k; //목표

	cin >> n >> k;

	int dp[10001] = { 0 ,};
	int cost[1001]= { 0 ,};

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	
	dp[0] = 1;
	//dp
	for (int i = 1; i <= n; i++) {
		for (int j = cost[i]; j <= k; j++) {
			dp[j] += dp[j - cost[i]];
		}
	}

	cout << dp[k];
	return 0;
}