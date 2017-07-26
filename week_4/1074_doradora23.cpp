#include <iostream>
#include <math.h>
using namespace std;

int findNumber(int x, int y, int length, int r, int c, int startNumber)
{
	if (length == 2)
	{
		if (x != r)
			startNumber += 2;
		if (y != c)
			startNumber += 1;
		return startNumber;
	}
	else
	{
		if (r - x >= length / 2)
		{
			startNumber += 2 * (length / 2)*(length / 2);
			x += length / 2;
		}
		if (c - y >= length / 2)
		{
			startNumber += 1 * (length / 2)*(length / 2);
			y += length / 2;
		}
		return findNumber(x, y, length / 2, r, c, startNumber);
	}
}
int main()
{
	int n,r,c;

	cin >> n >> r >> c;

	cout << findNumber(0, 0, pow(2, n), r, c, 0);
	return 0;
}