#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	int i = 1;
	int up, down;
	if (num == i) {
		up = 1;
		down = 1;
		cout << up << "/" << down << endl;
		return 0;
	}
	
	while(1){
		int prev = i*(i - 1) / 2;
		int next = i*(i + 1) / 2;
	
		if (num > prev&&num <= next) {
			if (i % 2 == 1) {
				up = i-(num - prev - 1);
				down = 1 + (num - prev - 1);
			}
			else {
				up = 1 + (num - prev - 1);
				down = i - (num - prev - 1);
			}
			break;
		}
		i++;
	}
	cout << up << "/" << down << endl;
	return 0;
}