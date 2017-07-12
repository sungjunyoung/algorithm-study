#include <iostream>
using namespace std;

int main()
{
	int X;
	cin >> X;
	int result = 0;

	int D[1000001] = { 0, };

	for (int i = 1; i <= X; i++)
	{
		if (i == 1)
		{
			D[i] = 0;
			continue;
		}

		result = D[i - 1] + 1;
		if (i % 2 == 0 && result > D[i / 2] + 1) result = D[i / 2] + 1;
		if (i % 3 == 0 && result > D[i / 3] + 1) result = D[i / 3] + 1;

		D[i] = result;
	}
	cout << D[X];

	return 0;
}