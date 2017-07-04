#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int num=0;
	int a = 0;
	char ch[81];
	cin >> num;
	while (num) {
		cin >> ch;
		int hap = 0;
		for (int i = 0; i < strlen(ch); i++) {
			if (ch[i]== 'O') {
				a = i - 1;
				hap++;
				while (ch[a] == 'O') {
						hap++;
						a--;
					}
				}
		}
			cout << hap << endl;

		num--;
	}

	return 0;
}