#include <iostream>
#include <algorithm>
using namespace std;
#define PI       3.14159265358979323846
int main()
{
	int ki[9];
	for (int a = 0; a < 9; a++) {
		cin >> ki[a];
	}
	int i;
	int j;
	int height;
	int sol[7];
	//(1,2),(1,3),.....,(2,3),(2,4),....,(8,9)까지 검사
	for (i = 0; i < 8; i++) {
		for (j = i + 1; j < 9; j++) {
			height = 0;
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j)
					continue;
				height += ki[k];
			}
			if (height == 100) {
				int idx = 0;
				for (int b = 0; b < 9; b++) {
					if (b == i || b == j)
						continue;
					sol[idx] = ki[b];
					idx++;
				}
				sort(sol, sol+7);
				for (int b = 0; b < 7; b++) {
					cout << sol[b] << endl;
				}
				return 0;
			}
		}
	}
	return 0;
}