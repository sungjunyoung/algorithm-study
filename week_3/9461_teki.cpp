#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main() {
	int T;
	cin >> T;
	//답의 크기를 유추해서 어떤 정수형을 쓸지 결정합시다
	long long tri[101];
	tri[1] = 1;
	tri[2] = 1;
	tri[3] = 1;
	//dp
	for (int i = 4; i <= 100; i++) {
		tri[i] = tri[i - 3] + tri[i - 2];
	}
	int N;
	//print
	//보기 출력 잘보고 endl할지 안할지 잘보자
	while (T--) {
		cin >> N;
		cout << tri[N] <<endl;
	}
	return 0;
}