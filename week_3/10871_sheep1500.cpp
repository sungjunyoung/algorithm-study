#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, x;
	cin >> n>>x;
	vector<int> ar;
	vector<int>::iterator ai;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		ar.push_back(num);
	}
	for (ai = ar.begin(); ai != ar.end(); ai++) {
		if (*ai < x) {
			cout << *ai << " ";
		}
	}

	return 0;
}