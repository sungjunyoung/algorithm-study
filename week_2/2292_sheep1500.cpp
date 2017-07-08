#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;
	while (num < 1 || num>1000000000)cin >> num;
	int i = 1;
	while (1) {
		int prev = 3 * (i - 1)*i + 1;
		int next = 3 * (i +1)*i + 1;

		if (num > prev&&num < next) {
			i++;
			break;
		}
		else if (num == prev) {
			break;
		}
		i++;
	}
	cout << i << endl;
	return 0;
}