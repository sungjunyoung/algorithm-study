#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n, m, k;
	int a[100][100];
	int b[100][100];
	int result[100][100] = { 0, };
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	cin >> m >> k;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < k; j++)
			cin >> b[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < k; j++)
			for (int l = 0; l < m; l++)
			{
				result[i][j] += a[i][l] * b[l][j];
			}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}