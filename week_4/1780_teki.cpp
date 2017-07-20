#include <iostream>
#include <algorithm>
using namespace std;
int a[2188][2188];
int cnt[3] = { 0 };

void count(int row_s, int row_e, int col_s, int col_e) {
	int p = a[row_s][col_s];
	bool check = true;
	//해당 구역을 검사
	for (int i = row_s; i <= row_e&&check; i++) {
		for (int j = col_s; j <= col_e&&check; j++) {
			if (a[i][j] != p)
				check = false;
		}
	}
	//해당 구역이 하나의 숫자로 이루어져 있으면
	if (check) {
		cnt[p + 1]++;
		return;
	}
	//여러개의 숫자로 이루어져 있으면 9개로 분할
	else {
		int d = (row_e - row_s + 1) / 3;
		//1
		count(row_s, row_s + d - 1, col_s, col_s + d - 1);
		//2
		count(row_s, row_s + d - 1, col_s + d, col_s + d + d - 1);
		//3
		count(row_s, row_s + d - 1, col_s + d + d, col_s + d + d + d - 1);
		//4
		count(row_s + d, row_s + d + d - 1, col_s, col_s + d - 1);
		//5
		count(row_s + d, row_s + d + d - 1, col_s + d, col_s + d + d - 1);
		//6
		count(row_s + d, row_s + d + d - 1, col_s + d + d, col_s + d + d + d - 1);
		//7
		count(row_s + d + d, row_s + d + d + d - 1, col_s, col_s + d - 1);
		//8
		count(row_s + d + d, row_s + d + d + d - 1, col_s + d, col_s + d + d - 1);
		//9
		count(row_s + d + d, row_s + d + d + d - 1, col_s + d + d, col_s + d + d + d - 1);
	}

}
int main() {
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
		}
	}

	count(1, N, 1, N);
	cout << cnt[0] << endl;
	cout << cnt[1] << endl;
	cout << cnt[2] << endl;
	return 0;
}