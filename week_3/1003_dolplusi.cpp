#include <iostream>
using namespace std;
int one = 0, zero = 0;
int fibonacci(int n) {
	if (n == 0) {
		zero++;
		return 0;
	}
	else if (n == 1) {
		one++;
		return 1;
	}
	else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	int T, N;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> N;
		fibonacci(N);
		cout << zero << " " << one << endl;
		zero = 0; one = 0;
	}
	
	return 0;
}