#include <iostream>
#include <string>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
int dp[1001][1001] = {0};

int main() {
	string a;
	string b;
	cin >> a >> b;
	//dp
	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			//같으면 +1
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			//다르면 큰걸 선택
			else
				dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[a.size()][b.size()];
	return 0;
}