#include <iostream>
using namespace std;

int main() {
	int zeroTonine[10]; fill_n(zeroTonine, 10, 0);
	int A, B, C, result; 
	cin >> A >> B >> C;
	result = A * B * C;

	while (result != 0) {
		int num = result % 10; result /= 10;
		zeroTonine[num]++;
	}
	
	for (int i = 0; i < 10; i++){
		cout << zeroTonine[i] << endl;
	}
}