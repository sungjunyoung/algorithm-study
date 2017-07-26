#include <iostream>
#include <math.h>
using namespace std;

void func(int input[][2500],int x, int y, int size, int& neg, int& zero, int& pos)
{
	int first = input[x][y];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (first != input[x+i][y+j])
			{
				func(input, x, y,  size / 3, neg, zero, pos);
				func(input, x, y + size / 3, size / 3, neg, zero, pos);
				func(input, x, y + 2 * size / 3, size / 3, neg, zero, pos);
				func(input, x + size / 3, y, size / 3, neg, zero, pos);
				func(input, x + size / 3, y + size / 3, size / 3, neg, zero, pos);
				func(input, x + size / 3, y + 2 * size / 3, size / 3, neg, zero, pos);
				func(input, x + 2 * size / 3, y, size / 3, neg, zero, pos);
				func(input, x + 2 * size / 3, y + size / 3, size / 3, neg, zero, pos);
				func(input, x + 2 * size / 3, y + 2 * size / 3, size / 3, neg, zero, pos);

				return;
			}
		}
	}
	if (first == -1)
		neg++;
	else if (first == 0)
		zero++;
	else if (first == 1)
		pos++;
	return;
}

int main()
{
	int n;
	int input[2500][2500];
	int neg = 0, zero = 0, pos = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j=0; j<n;j++)
			cin >> input[i][j];
	}

	func(input, 0, 0, n, neg, zero, pos);

	cout << neg << endl << zero << endl << pos;

	

	return 0;
}