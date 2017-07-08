#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence;
	getline(cin, sentence);
	int cnt = 1;
	for (int i = 1; i < (int)sentence.length() - 1; i++) {
		if (sentence[i] == ' ')
			cnt++;
	}
	// ' '만 있을 때
	if (sentence[0] == ' ' && sentence.length() == 1)
		cnt = 0;
	if (sentence.length())
		cout << cnt;
	else // enter만 쳤을 때
		cout << 0;
	return 0;
}