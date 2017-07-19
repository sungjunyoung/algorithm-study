#include <iostream>
#include <string>
using namespace std;

int main() {
	int A;
	int B;
	int C;

	cin >> A >> B >> C;

	int mul = A*B*C;
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = -1;
	}

	int i = 0;
	while (mul) {
		arr[i] = (mul % 10);
		mul /= 10;
		i++;
	}


	int cnt[10] = { 0 };

	for (int i = 0; arr[i] != -1 && i<10; i++) {
		cnt[arr[i]]++;
	}

	for (int i = 0; i < 10; i++)
		cout << cnt[i] << endl;


	return 0;
}