#include <iostream>
using namespace std;
int dp[100010];
int num[100010];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];
	for (int i = 1; i <= n; i++) {
		if (dp[i - 1] + num[i] < num[i])
			dp[i] = num[i];
		else
			dp[i] = dp[i - 1] + num[i];
	}

	int max = dp[1];
	for (int i = 2; i <= n; i++) {
		if (max < dp[i])
			max = dp[i];
	}
	cout << max;
	return 0;
}