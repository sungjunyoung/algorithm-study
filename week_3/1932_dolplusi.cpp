#include <iostream>
using namespace std;

int main()
{
	int n; cin >> n;
	int max = -1;
	int pyramid[501][501] = { 0, };
	int D[501][501] = { 0, };

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> pyramid[i][j];
	D[1][1] = pyramid[1][1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1)		// 맨 앞자리는 윗층의 맨 앞자리 대입
				D[i][j] = D[i - 1][j] + pyramid[i][j];
			else if (j == n)	// 맨 뒷자리는 윗층의 맨 뒷자리 대입
				D[i][j] = D[i - 1][j - 1] + pyramid[i][j];
			else {			// 나머지는 윗층 왼쪽, 오른쪽 중 제일 큰 값을 대입
				D[i][j] = ((D[i - 1][j - 1] > D[i - 1][j]) ? D[i - 1][j - 1] : D[i - 1][j]) + pyramid[i][j];
			}
		}
	}

	for (int j = 1; j <= n; j++){
		max = (max > D[n][j]) ? max : D[n][j];
	}
	cout << max;
}