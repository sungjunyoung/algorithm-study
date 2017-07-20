#include <iostream>
using namespace std;
int A[101][101];
int B[101][101];
int sol[101][101];
int main() {
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}

	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int k = 0; k < K; k++) {
			for (int j = 0; j < M; j++) {
				sol[i][k] += (A[i][j] * B[j][k]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << sol[i][j] <<" ";
		}
		cout << '\n';
	}
	return 0;
}