#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

	int num;
	int point[300];
	int result[300];

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> point[i];
	}

	result[0] = point[0];
	result[1] = point[0] + point[1];
	result[2] = max(point[0], point[1]) + point[2];
	result[3] = max(result[0] + point[2] + point[3], result[1] + point[3]);



	for (int i = 3; i < num; i++) {
		result[i] = point[i] + max(point[i - 1] + result[i - 3], result[i - 2]);
	}

	cout << result[num - 1];

	return 0;

}
