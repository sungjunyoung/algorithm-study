#include <iostream>
using namespace std;
int main() {
	int* arr = new int[1000001];
	//초기화
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	int a;
	int b;
	//dp
	for (int i = 4; i < 1000001; i++) {
		//조건 3개
		// 1. 3으로 나누어떨어지면 3으로 나눈다
		if (i % 3 == 0) {
			a = arr[i / 3] + 1;
			b = arr[i - 1] + 1;
			if (a > b)
				arr[i] = b;
			else
				arr[i] = a;
		}
		// 2. 2로 나누어떨어지면 2로 나눈다
		else if (i % 2 == 0) {
			a = arr[i / 2] + 1;
			b = arr[i - 1] + 1;
			if (a > b)
				arr[i] = b;
			else
				arr[i] = a;
		}
		// 3. 1을 뺀다 >> 2,3으로도 안나누어떨어지면 1을 뺀다
		else {
			arr[i] = arr[i - 1] + 1;
		}
	}
	int input;
	cin >> input;
	cout << arr[input] << endl;

	return 0;
}