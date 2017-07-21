#include <iostream>
#include <string>
using namespace std;
string arr[65];

void check(int rs, int re, int cs, int ce) {
	bool chk = true;
	char tmp = arr[rs][cs];
	//같은숫자로 이루어져있는지 쳌쳌
	for (int i = rs; i <= re && chk; i++) {
		for (int j = cs; j <= ce && chk; j++) {
			if (tmp != arr[i][j])
				chk = false;
		}
	}

	if (chk) {
		cout << tmp;
	}
	else {
		int d = (re-rs + 1) / 2;
		cout << '(';
		//왼쪽 상단
		check(rs, rs + d - 1, cs, cs + d - 1);
		//오른쪽 상단
		check(rs, rs + d - 1, cs + d, ce);
		//왼쪽 하단
		check(rs + d, re, cs, cs + d - 1);
		//오른쪽 하단
		check(rs + d, re, cs + d, ce);
		cout << ')';
	}
	return;
}

int main() {
	int N;
	cin >> N;
	string a;
	for (int i = 1; i <= N; i++){
		cin >> arr[i];
	}

	check(1, N, 0, N-1);

	return 0;
}