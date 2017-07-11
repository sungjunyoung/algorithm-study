#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, result = 0;
	int D[101][10] = { 0, };
	cin >> N;
	for (int i = 1; i <= 9; i++) {
		D[1][i] = 1;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 9) {
				D[i][j] = D[i - 1][j - 1] % 1000000000;
				continue;
			}
			if (j == 0) {
				D[i][j] = D[i - 1][j + 1] % 1000000000;
				continue;
			}
			D[i][j] = (D[i - 1][j + 1] + D[i - 1][j - 1]) % 1000000000;
		}
	}

	for (int i = 0; i <= 9; i++) {
		result = (result + D[N][i]) % 1000000000;
	}
	cout << result % 1000000000;
}