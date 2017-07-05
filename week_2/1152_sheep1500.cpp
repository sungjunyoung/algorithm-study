#include <iostream>
#include <string>

using namespace std;

int main()
{
		string str;
		int num = 0;
		do {
			getline(cin, str);
		} while (str.size() > 1000001);

		for (int i = 1; i < str.size() - 1; i++) {
			if (str[i] == ' '&&str[i - 1] != ' '&&str[i + 1] != ' ')num++;
		}
		if (str[str.size() - 1] != ' '&&str[str.size() - 2] == ' '&&str[str.size() - 3] == ' ')num++;
		cout << ++num << endl;



	return 0;
}