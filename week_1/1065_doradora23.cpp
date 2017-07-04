#include <iostream>
using namespace std;

int main() {
	int num, temp,result;
	int newDif, oriDif;
	bool chk = true;
	cin >> num;

	if (num <= 99)
		result = num;
	else {
		result = 99;
		for (int i =100; i <= num; i++)
		{
			chk = true;
			oriDif = (i / 10) % 10 - i % 10;
			temp = i/10;
			while (temp >= 10)
			{
				newDif = (temp / 10) % 10 - temp % 10;
				temp = temp / 10;
				if (newDif != oriDif)
				{
					chk = false;
					break;
				}
			}
			if (chk)
				result++;

		}
	}

	cout << result;
	return 0;
}