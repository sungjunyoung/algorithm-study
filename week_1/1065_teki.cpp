#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;
	//자리수 저장할 배열
	int arr[3];	
	//정답
	int cnt = 99;
	int temp;
	//100보다 작으면 print num
	if (num < 100) {
		cout << num;
		return 0;
	}
	//100보다 크면
	else {
		for (int i = 100; i <= num; i++) {
			//1000은 등차가 아님
			if (i == 1000)
				break;
			//자리수 배열에 넣음
			temp = i;
			arr[0] = temp % 10;
			temp /= 10;
			arr[1] = temp % 10;
			temp /= 10;
			arr[2] = temp % 10;
			temp /= 10;
			//등차수열인지 비교
			if ((arr[0] - arr[1]) == (arr[1] - arr[2]))
				cnt++;
		}
	}
	cout <<cnt;
	return 0;
}