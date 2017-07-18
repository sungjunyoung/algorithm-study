#include <iostream>
#include <algorithm>
using std::cin;
using std::cout;
int main() {
	int pos[3];
	cin >> pos[0] >> pos[1] >> pos[2];
	std::sort(&pos[0],&pos[2]);
	cout << std::max(pos[2] - pos[1], pos[1] - pos[0]) - 1;
	return 0;
}