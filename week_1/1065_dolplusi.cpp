#include <iostream>
#include <cmath>
using namespace std;

bool isHansu(int N) {
	bool check = true;
	bool findMaxCipher = false;
	int Narr[4]; int num = 0;
	std::fill_n(Narr, 4, 0);
	for (int maxCipher = 4; maxCipher >= 0; maxCipher--) {
		if ((N / (int)pow(10, maxCipher)) == 0 && !findMaxCipher) {
			continue;
		}
		findMaxCipher = true;
		Narr[num] = N / (int)pow(10, maxCipher) % 10;
		num++;
	}
	if (num == 1)
		return true;

	int differ = Narr[0] - Narr[1];
	for (int i = 1; i < num - 1; i++) {
		if (Narr[i] - Narr[i + 1] != differ)
			check = false;
	}
	return check;
}

int main() {
	int cnt = 0; int N; cin >> N;
	isHansu(N);
	
	for (int i = 1; i <= N; i++) {
		if (isHansu(i))
			cnt++;
	}
	cout << cnt;
	return 0;
}