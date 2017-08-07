#include <iostream>
using namespace std;

#define MAX 100
int N;
int M;
int K;
int matrixA[MAX + 1][MAX + 1];
int matrixB[MAX + 1][MAX + 1];

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> matrixA[i][j];
    cin >> M >> K;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < K; ++j)
            cin >> matrixB[i][j];
    int sum;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) {
            sum = 0;
            for (int m = 0; m < M; ++m) {
                sum += matrixA[i][m] * matrixB[m][j];
            }
            cout<<sum<<' ';
        }
        cout<<endl;
    }
    return 0;
}