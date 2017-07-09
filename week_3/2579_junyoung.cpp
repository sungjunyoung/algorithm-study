#include <iostream>
using namespace std;

#define ONE 1
#define TWO 2

int D[3][301];
int P[301];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> P[i];
  }

  D[ONE][1] = P[1];
  D[TWO][1] = P[1];

  for (int i = 2; i <= n; i++) {
    D[ONE][i] = D[TWO][i - 2] + P[i];
    D[TWO][i] = max(D[ONE][i - 1] + P[i], D[TWO][i - 2] + P[i]);
  }

  int result = max(D[ONE][n], D[TWO][n]);
  cout << result << endl;
}
