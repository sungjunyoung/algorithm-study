#include <iostream>
using namespace std;

int main() {
	int num;
	cin >> num;

	int arr[3];
	int cnt = 99;
	int temp;
	if (num < 100) {
		cout << num;
		return 0;
	}

	else {
		for (int i = 100; i <= num; i++) {
			if (i == 1000)
				break;
			temp = i;
			arr[0] = temp % 10;
			temp /= 10;
			arr[1] = temp % 10;
			temp /= 10;
			arr[2] = temp % 10;
			temp /= 10;
			if ((arr[0] - arr[1]) == (arr[1] - arr[2]))
				cnt++;
		}
	}

	cout << cnt;
	return 0;
}