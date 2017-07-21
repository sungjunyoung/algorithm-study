#include <iostream>
using namespace std;

int page[501];
int dp[501][501];
int main() {
	int T;
	cin >> T;
	int N;
	while (T--) {
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> page[i];

		for (int i = 0; i < N; i++) {
			dp[i][i + 1] = page[i] + page[i + 1];
		}
		long long min;
		long long cost;
		//dp
		//diagonal calc~
		for (int d = 2; d <= N; d++) {
			for (int i = 0; i + d <= N; i++) {
				//cost calc
				cost = 0;
				for (int a = i; a <= i + d; a++) {
					cost += page[a];
				}

				//dp min calc
				min = 1099999999;
				for (int k = i; k < i + d; k++) {
					if (min > dp[i][k] + dp[k + 1][i + d] + cost)
						min = dp[i][k] + dp[k + 1][i + d] + cost;
				}
				dp[i][i + d] = min;
			}
		}
		cout << dp[1][N] << endl;
	}
	return 0;
}