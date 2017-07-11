#include <iostream>
#include <algorithm>
using namespace std;

int paint(int input[][3], int house_num) {
	int result[1000][3] = { 0, };
	for (int i = 0; i < 3; i++) {
		result[0][i] = input[0][i];
	}

	for (int i = 1; i < house_num; i++) {
		for (int j = 0; j < 3; j++) {
			result[i][j % 3] = min(result[i - 1][(j + 1) % 3] + input[i][j % 3], result[i - 1][(j + 2) % 3] + input[i][j % 3]);
		}
	}
	return min(min(result[house_num - 1][0], result[house_num - 1][1]), result[house_num - 1][2]);
}
int main()
{
	int input[1000][3]; // Red Green Blue
	int house_num;
	cin >> house_num;
	for (int i = 0; i < house_num; i++) {
		cin >> input[i][0] >> input[i][1] >> input[i][2];
	}
	cout << paint(input, house_num);
	return 0;
}