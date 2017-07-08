#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int num;

	cin >> num;
	if (num == 1) {
		cout << "1/1";
		return 0;
	}

	int k = 1;
	while (1) {
		if (num > (k*k + k) / 2 && num <= ((k + 1)*(k + 1) + k + 1) / 2) {
			break;
		}
		k++;
	}
	int a = num - ((k*k + k) / 2) - 1;

	if (k % 2 == 1) {
		cout << 1 + a << "/" << k + 1 - a;
	}
	else {
		cout << k + 1 - a << "/" << 1 + a;
	}

	return 0;
}