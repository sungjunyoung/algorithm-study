#include <iostream>
using namespace std;


void fibo_count(int count[][2], int n)
{
	count[0][0] = 1;
	count[1][0] = 0;
	count[0][1] = 0;
	count[1][1] = 1;

	for (int i = 2; i <= n; i++)
	{
		if (!count[i][0]) {
			count[i][0] = count[i - 1][0] + count[i - 2][0];
			count[i][1] = count[i - 1][1] + count[i - 2][1];
		}
	}
	cout << count[n][0] << " " << count[n][1] << endl;
}

int main()
{
	int case_num;
	int count[41][2] = { 0, };
	cin >> case_num;
	int input[100000];
	for (int i = 0; i < case_num; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < case_num; i++) {
		fibo_count(count, input[i]);
	}
	return 0;
}