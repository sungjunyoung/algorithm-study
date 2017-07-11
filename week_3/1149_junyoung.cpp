#include <iostream>
using namespace std;

#define R 0
#define G 1
#define B 2

int D[3][1001];
int P[3][1001];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> P[R][i] >> P[G][i] >> P[B][i];
  }

  D[R][1] = P[R][1];
  D[G][1] = P[G][1];
  D[B][1] = P[B][1];

  for (int i = 2; i <= n; i++) {
    D[R][i] = min(D[G][i - 1] + P[R][i], D[B][i - 1] + P[R][i]);
    D[G][i] = min(D[R][i - 1] + P[G][i], D[B][i - 1] + P[G][i]);
    D[B][i] = min(D[R][i - 1] + P[B][i], D[G][i - 1] + P[B][i]);
  }

  int result = min(D[R][n], D[G][n]);
  result = min(result, D[B][n]);

  cout << result << endl;
}
