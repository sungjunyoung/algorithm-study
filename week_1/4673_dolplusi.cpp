#include <iostream>
using namespace std;

bool checkNotSelfNumb[10001];

int Dfunc(int num) {
	int result = num;
	int oneNum;
	while (num != 0) {
		oneNum = num % 10; num /= 10;
		result += oneNum;
	}
	return result;
}

int main() {
	int dump = 0;

	for (int cnt = 1; dump <= 10036; cnt++) {
		dump = Dfunc(cnt);
		checkNotSelfNumb[dump] = true;
	}
	for (int cnt = 1; cnt < 10001; cnt++) {
		if (checkNotSelfNumb[cnt] == false)
			cout << cnt << endl;
	}
	return 0;
}