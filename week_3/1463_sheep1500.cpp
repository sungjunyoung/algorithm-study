#include <iostream>

using namespace std;

int go(int n);

int D[1000001];

int main()
{
	int num;
	cin >> num;

	go(num);

	cout << D[num] << endl;
	return 0;
}
int go(int n) {
	
	if (n == 1)return 0;
	if (D[n] > 0) return D[n];
	
	D[n] = go(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = go(n / 2) + 1;
		if (D[n] > temp) D[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = go(n / 3) + 1;
		if (D[n] > temp) D[n] = temp;
	}
	return D[n];
}