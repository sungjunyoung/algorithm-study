#include <iostream>
using namespace std;

int main()
{

	int da[8];
	int check = 0;
	int check1 = 0;
	for (int i = 0; i < 8; i++) {
		cin >> da[i];
	}
	
	for (int i = 0; i < 8; i++) {
		if (da[i] != i + 1) {
			check = 1;
		}
		if (da[i] != 8 - i) {
			check1 = 1;
		}
		/*
		if (da[i] == i + 1)check = 0;
		else if (da[i] == 8 - i)check = 1;
		else check = 2; break;
		여기서 0일때 ascending / 1일때 descending /2일 때 mixed 하는 코드로 
		짰었는데 계속 틀렸다고 나오는데 이유 알면 말좀 해주시오!
		*/
	}
	if(check==0)
			cout << "ascending"; 
	else if(check1==0)
			cout << "descending";
	else
			cout << "mixed"; 
		
	
	return 0;
}