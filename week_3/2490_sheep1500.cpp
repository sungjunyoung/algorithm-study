#include <iostream>

using namespace std;

int main()
{
	int num1, num2,num3,num4;
	int count = 3;
	while(count>=1){
		cin >> num1 >> num2 >> num3 >> num4;

		int hap = num1 + num2 + num3 + num4;
		switch (hap)
		{
			case 0:
				cout << "D" << endl; break;
			case 1:
				cout << "C" << endl; break;
			case 2:
				cout << "B" << endl; break;
			case 3:
				cout << "A" << endl; break;
			case 4:
				cout << "E" << endl; break;
			default:
				break;
		}
		count--;
	}
	return 0;
}