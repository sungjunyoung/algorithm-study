#include <iostream>
using namespace std;

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))  

int main()
{
	int N;
	cin >> N;

	int RGB[1001][3] = { 0, };
	int D[1001][3] = { 0, };
	// index == 0 == R, index == 1 == G, index == 2 == B

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
			cin >> RGB[i][j];
	}

	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
		{
			D[1][0] = RGB[1][0]; D[1][1] = RGB[1][1]; D[1][2] = RGB[1][2];
		}
		else
		{
			D[i][0] = MIN(D[i - 1][1], D[i - 1][2]) + RGB[i][0];
			D[i][1] = MIN(D[i - 1][0], D[i - 1][2]) + RGB[i][1];
			D[i][2] = MIN(D[i - 1][1], D[i - 1][0]) + RGB[i][2];
		}
	}

	cout << MIN(MIN(D[N][0], D[N][1]), D[N][2]);

}