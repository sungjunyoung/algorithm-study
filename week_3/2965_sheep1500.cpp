#include <iostream>

using namespace std;

int D[101][101][101] = {0};

int recurK(int left,int middle,int right);
int main() {

	int a, b, c;
	cin >> a >> b >> c;

	recurK(a, b, c);

	cout << D[a][b][c] << endl;

	return 0;
}
int recurK(int left, int middle, int right) {
	if (middle -left== 1 && right - middle == 1) {
		return 0;
	}
	if (middle - left >= right - middle && middle - left > 1) {
		recurK(left, middle - 1, middle);
		D[left][middle][right] = D[left][middle - 1][middle] + 1;
	}
	else if (middle - left <= right - middle && right - middle > 1) {
		recurK(middle,middle + 1,right);
		D[left][middle][right] = D[middle][middle + 1][right] + 1;
	}

}
