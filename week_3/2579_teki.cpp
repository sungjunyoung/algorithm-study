#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int num;
	cin >> num;		//case 개수 입력
	

	int score[301] = {0};	//계단점수
	int dp[301][3] = {0};	//dp 배열
	for (int i = 1; i <= num; i++) {	//점수 입력
		cin >> score[i];
	}


	dp[1][1] = score[1];	//초기화
	dp[1][2] = score[1];

	for (int i = 2; i <= num; i++) {
		//dp[i][1] >> 직전 계단을 밟았을때(1단 점프해서 현재 계단으로 왔을때)
		//dp[i][2] >> 직전 계단을 안밞았을때(2단 점프해서 현재 계단으로 왔을때)
		dp[i][1] = dp[i - 1][2] + score[i];
		dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + score[i];
	}

	cout << max(dp[num][1], dp[num][2]);
	return 0;

}