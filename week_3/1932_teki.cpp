#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int caseNum;
	cin >> caseNum;		//case 개수 입력
	

	//배열 동적 할당
	int** arr = new int*[501];
	for (int i = 1; i < 501; i++)
		arr[i] = new int[i];
	
	int** dp = new int*[501];
	for (int i = 1; i < 501; i++)
		dp[i] = new int[i];


	//배열 입력
	for (int i = 1; i <= caseNum; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> arr[i][j];
		}
	}

	//dp
	dp[1][1] = arr[1][1];

	for (int i = 2; i <= caseNum; i++) {
		for (int j = 1; j <= i; j++) {
			//3가지 경우로 나눔
			//1. 첫번째 열일때
			//2. 마지막 열일때
			//3. 1,2외의 경우
			if (j == 1) {
				dp[i][j] = arr[i][j] + dp[i - 1][j];
			}
			else if (i == j) {
				dp[i][j] = arr[i][j] + dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = arr[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}

	int max = dp[caseNum][1];

	for (int i = 2; i <= caseNum; i++) {
		if (max <dp[caseNum][i])
			max = dp[caseNum][i];
	}
	cout << max;
	
	return 0;
}