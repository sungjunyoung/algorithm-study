#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int caseNum;
	cin >> caseNum;		//case 개수 입력
	
	int cost[1001][3];

	int dp[1001][3];

	for (int i = 1; i <= caseNum; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];

	if (caseNum == 1) {
		//가장 비용이 작은거 하나 출력
		int min = cost[1][0];
		for (int i = 1; i < 3; i++) {
			if (min > cost[1][i])
				min = cost[1][i];
		}
		cout << min;
		return 0;
	}

	else if (caseNum == 2) {
		//가장 비용이 작은 조합 하나 출력
		int min1 = cost[1][0];
		int min2 = cost[2][0];
		for (int i = 1; i < 3; i++) {
			if (min1 > cost[1][i])
				min1 = cost[1][i];
	
			if (min2 > cost[2][i])
				min2 = cost[2][i];
		}

		cout << min1 + min2;
		return 0;
	}

	else {
		//dp
		for (int i = 2; i <= caseNum; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
		}

		int m = min(dp[caseNum][0], dp[caseNum][1]);
			m = min(m,dp[caseNum][2]);
			cout << m;
	}
	return 0;
}