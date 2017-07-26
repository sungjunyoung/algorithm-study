#include <iostream>
#include <math.h>
using namespace std;
long long  N, r, c;
long long  find(long long row_s, long long row_e, long long col_s, long long col_e) {
	int d = (row_e - row_s)/2 + 1;
	if (row_e - row_s == 1)
		return (r + 1 - row_s) * 2 + (c + 1 - col_s + 1);
	//1,2
	if (r + 1 >= row_s && r + 1 <row_s +d) {
		if (c + 1 >= col_s && c + 1 < col_s + d)
			return find(row_s, row_s + d -1, col_s, col_s + d - 1);
		if(c + 1 > (col_e) / 2 && c + 1 <= col_e)
			return ((row_e - row_s + 1)*(row_e - row_s + 1))/4 + find(row_s, row_s + d - 1, col_s + d, col_e);
	}
	//3,4
	if(r + 1 >= row_s + d && r + 1 <= row_e){
		if (c + 1 >= col_s && c + 1 < col_s + d)
			return 2 *((row_e - row_s + 1)*(row_e - row_s + 1))/4 + find(row_s + d, row_e, col_s, col_s + d - 1);
		if (c + 1 > (col_e) / 2 && c + 1 <= col_e)
			return 3 *((row_e - row_s + 1)*(row_e - row_s + 1))/4 + find(row_s + d, row_e, col_s + d, col_e);
	}
}
int main() {
	cin >> N >> r >> c;
	cout << find(1, pow(2, N), 1, pow(2, N)) << endl;
	return 0;
}