#include <iostream>
using namespace std;
int fib[1500000];
int main() {
	long long n;
	cin >> n;
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 1;

	for (int i = 3; i < 1500000; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		fib[i] %= 1000000;
	}
	cout << fib[n % 1500000];
	return 0;
}