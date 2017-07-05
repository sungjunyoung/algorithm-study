#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main() {
	string input;									//입력받을 string
	getline(cin, input);							//space bar도 포함해서 string입력받음 >> cin은 space bar를 입력의 끝으로 판단
	istringstream iss(input);						//stringstream
	string token;									//기준문자를 기준으로 string을 나눠 저장할 string
	vector<string> cnt;								//나눈 string을 저장할 vector

	while (getline(iss, token, ' '))				//input의 끝까지, 공백을 만날때마다 token에 저장하며 반복
		cnt.push_back(token);

	if (input[0] == ' ')							//inpue의 첫글자가 공백이면 size-1
		cout << cnt.size() - 1;
	else
		cout << cnt.size();

	return 0;
}