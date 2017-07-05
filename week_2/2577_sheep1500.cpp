#include <iostream>
#include <string>

using namespace std;
bool checkNum(int num1, int num2, int num3);

int main()
{
	int num1, num2, num3;
	int gop;
	int arr[10] = { 0 };
	string str;
	do {
		cin >> num1 >> num2 >> num3;
	} while (checkNum(num1, num2, num3));

	gop = num1*num2*num3;
	str = to_string(gop);
	
	for (int i = 0; i < str.length(); i++)
	{
		//str[i] 는 char형이여서 atoi(const *char)의 매개변수 타입과 맞지 않네요
		//char을 int 로 바꾸기 위해 -'0' 해줬어욤
		int check = str[i]-'0';
		arr[check]++;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}


	return 0;
}
bool checkNum(int num1, int num2, int num3) {
	if (num1 < 100 || num1 >= 1000)return true;
	if (num2 < 100 || num2 >= 1000)return true;
	if (num3 < 100 || num3 >= 1000)return true;

	return false;
}