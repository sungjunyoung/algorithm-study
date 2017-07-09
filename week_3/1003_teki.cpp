#include <iostream>
#include <string>
using namespace std;
int main() {
	int caseNum;
	cin >> caseNum;		//case 개수 입력
	
	int fib[41][2];		//피보나치 연산횟수 배열
	fib[0][0] = 1;
	fib[0][1] = 0;
	fib[1][0] = 0;
	fib[1][1] = 1;

	for (int i = 2; i < 41; i++) {		//배열 계산
		fib[i][0] = fib[i - 1][0] + fib[i - 2][0];
		fib[i][1] = fib[i - 1][1] + fib[i - 2][1];
	}

	int* input = new int[caseNum];		//test case 입력
	for (int i = 0; i < caseNum; i++)
		cin >> input[i];

	for (int i = 0; i < caseNum; i++)	//출력
		cout << fib[input[i]][0] << " " << fib[input[i]][1] << endl;

	return 0;
}