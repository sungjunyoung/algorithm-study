#include <iostream>
#include <string>
using namespace std;

int problemScore(string problem) {
	int result = 0;
	int continuos = 0; bool check = false;

	for (int i = 0; i < problem.length(); i++) {
		if (problem[i] == 'O')
			check = true;
		else
			check = false;
		if (check)
			continuos++;
		else
			continuos = 0;
		result += continuos;
	}
	return result;
}

int main() {
	int N;
	cin >> N;
	string* problems = new string[N];

	for (int i = 0; i < N; i++)
		cin >> problems[i];

	for (int i = 0; i < N; i++)
		cout << problemScore(problems[i]) << endl;

	return 0;
}