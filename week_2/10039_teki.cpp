#include <iostream>
#include <string>
using namespace std;


int main() {
	int arr[5];
	int sum = 0;

	/*
	각 학생의 점수를 입력받고
	해당점수가 40보다 작으면 40으로 변경한다
	그리고 점수를 sum에 더한다
	*/
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
		if (arr[i] < 40)
			arr[i] = 40;

		sum += arr[i];
	}

	cout << sum / 5;
	return 0;
}