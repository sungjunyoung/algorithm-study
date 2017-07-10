#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	unsigned long result[101][10] = { 0, };
	int n;
	long total = 0;

	cin >> n;

	result[1][0] = 0;
	for (int j = 1; j < 10; j++)
		result[1][j] = 1;
	for (int i = 2; i <= n; i++)
	{
		result[i][0] = result[i - 1][1];
		for (int j = 1; j < 9; j++)
		{
			result[i][j] = (result[i - 1][j - 1] + result[i - 1][j + 1]) % 1000000000;
		}
		result[i][9] = result[i - 1][8];
	}
	for (int j = 0; j < 10; j++) {
		total += result[n][j];
		total %= 1000000000;
	}

	cout << total;
	return 0;
}