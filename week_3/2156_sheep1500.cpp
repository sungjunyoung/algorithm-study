#include <iostream>

using namespace std;

int D[10001][3];
int A[10001];
int max(int num1, int num2, int num3);
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int amount;
		cin >> amount;
		A[i] = amount;
	}

	D[1][1] = A[1];
	D[2][0] = D[1][1];
	D[2][1] = A[2];
	D[2][2] = D[1][1]+A[2];

	for (int i = 3; i <= n; i++) {
		D[i][0] = max(D[i - 1][0],D[i - 1][1] ,D[i - 1][2]);
		D[i][1] = D[i - 1][0] + A[i];
		D[i][2] = D[i - 1][1] + A[i];
	}
	cout << max(D[n][0],D[n][1],D[n][2]) << endl;
}
int max(int num1, int num2, int num3) {
	if (num1 >= num2&&num1 >= num3)return num1;
	if (num2 >= num1&&num2 >= num3)return num2;
	if (num3 >= num2&&num3 >= num1)return num3;
	return 0;
}

