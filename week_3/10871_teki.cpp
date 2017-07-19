#include <iostream>
using std::cin;
using std::cout;
//using std::endl;
int main() {
	int arr[10000];
	int N;
	int X;
	cin >> N >> X;
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		if (arr[i] < X)
			cout << arr[i] << " ";
	}
	return 0;
}