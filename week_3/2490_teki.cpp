#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int arr[4];
	int cnt;
	for (int i = 0; i < 3; i++) {
		
		for (int j = 0; j < 4; j++) {
			cin >> arr[j];
		}
		cnt = 0;
		for (int j = 0; j < 4; j++) {
			cnt += arr[j];
		}
		if (cnt == 0)
			cout << "D" << endl;
		else if(cnt == 1)
			cout << "C" << endl;
		else if (cnt == 2)
			cout << "B" << endl;
		else if (cnt == 3)
			cout << "A" << endl;
		else
			cout << "E" << endl;
	}
	return 0;
}