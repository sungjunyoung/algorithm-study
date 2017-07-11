#include <iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int stair[301] = { 0, };
	int D[301][2] = { 0, };
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}

	D[1][0] = stair[1]; D[1][1] = stair[1];
	D[2][0] = stair[2]; D[2][1] = stair[2] + D[1][0];

	for (int i = 3; i <= n; i++) {
		D[i][1] = D[i - 1][0] + stair[i];
		D[i][0] = ((D[i - 2][0] > D[i - 2][1]) ? D[i - 2][0] : D[i - 2][1]) + stair[i];
	}

	if (D[n][0] > D[n][1])
		cout << D[n][0];
	else 
		cout << D[n][1];
}