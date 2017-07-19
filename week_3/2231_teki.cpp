#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int num;
	int cnt;
	for (int i = 1; i < 1000001; i++) {
		num = i;
		cnt = num;
		while (num) {
			cnt += (num % 10);
			num /= 10;
		}
		if (cnt == N) {
			cout << i;
			return 0;
		}
	}
	cout << '0';
	return 0;
}