#include <iostream>
#include <string>
using namespace std;

int main() {
	int A;
	int B;
	int C;

	cin >> A >> B >> C;								//입력

	int mul = A*B*C;
	int arr[10];

	fill_n(arr, 10, -1);							//배열초기화

	int i = 0;

	while (mul) {									//반복문을 돌면서 1의 자리부터 배열에 저장
		arr[i] = (mul % 10);
		mul /= 10;
		i++;
	}


	int cnt[10] = { 0 };							//카운트 배열 초기화

	for (int i = 0; arr[i] != -1 && i<10; i++) {	//arr배열의 끝까지 각 자리의 숫자 개수 카운트
		cnt[arr[i]]++;
	}

	for (int i = 0; i < 10; i++)					//출력
		cout << cnt[i] << endl;


	return 0;
}