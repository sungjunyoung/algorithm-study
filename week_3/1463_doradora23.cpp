#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int result[1000000] = { 0, };
	int input;

	result[2] = 1;
	result[3] = 1;

	cin >> input;

	for (int i = 4; i <= input; i++)
	{
		if (i % 2 == 0 && i % 3 == 0)
			result[i] = min(min(result[i - 1], result[i / 2]), result[i / 3]) + 1;
		else if (i % 2 == 0)
			result[i] = min(result[i - 1], result[i / 2]) + 1;
		else if (i % 3 == 0)
			result[i] = min(result[i - 1], result[i / 3]) + 1;
		else
			result[i] = result[i - 1] + 1;
	}

	cout << result[input];
	return 0;
}