#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int num;
	int input[500][500];
	int result[500][500] = { 0, };
	int maxRes = 0;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cin >> input[i][j];
		}
	}
	result[0][0] = input[0][0];
	for (int i = 1; i < num; i++)
	{
		result[i][0] = result[i - 1][0] + input[i][0];
		for (int j = 1; j < i; j++)
		{
			result[i][j] = max(result[i - 1][j - 1], result[i - 1][j]) + input[i][j];
		}
		result[i][i] = result[i - 1][i - 1] + input[i][i];
	}
	for (int i = 0; i < num; i++)
	{
		if (maxRes < result[num - 1][i])
			maxRes = result[num - 1][i];
	}
	cout << maxRes;
	return 0;

}