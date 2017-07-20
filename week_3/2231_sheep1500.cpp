#include <iostream>

using namespace std;

int main()
{
	int n;
	bool b=false;
	cin >> n;
	
	for (int i = n / 2; i < n; i++) {
		int hap=i;
		int count = hap;
		while (count > 0) {
			hap+=count % 10;
			count /= 10;
		}

		if (hap == n) {
			cout << i << endl;
			b = true;
			break;
		}
	}
	if (!b) { cout << 0 << endl; }

	return 0;
}