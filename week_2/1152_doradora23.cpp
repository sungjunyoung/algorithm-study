#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	int count = 0;
	getline(cin, str);
	if (str.size()) {
		if (str[0] != ' ')
			count++;
		for (int i = 0; i < str.size() - 1; i++)
		{
			if (str[i] == ' ' && str[i + 1] != ' ')
				count++;
		}
	}
	cout << count;
	return 0;
}