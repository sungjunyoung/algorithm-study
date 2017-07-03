#include <iostream>

using namespace std;
/*
int hanNum(int num);
int main()
{
	int num;
	int check = 0;
	cin >> num;
	
	if(num>0&&num<=10000){
		for (int i = 1; i <= num; i++) {
			if (i > 0 && i < 100)check++;
			else {
				if (hanNum(i) == 1)check++;
			}
		}
	}
	cout << check << endl;
	return 0;
}

int hanNum(int num) {
	int check1, check2;
	
	while(num>=100){
		check1 = num /10%10 - num % 10;
		check2 = num / 100 % 10 - num / 10 % 10;
		if (check1 != check2)return 0;
		else num /= 10;
	}

	return 1;
}*/