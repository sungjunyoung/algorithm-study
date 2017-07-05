#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int num;
	cin >> num;
	int k = 1;
	while (1) {
		if (num <= (3 * k*k - 3 * k + 1)) {
			cout << k;
			break;
		}
		k++;
	}

	return 0;
}