#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;

  int D[1000001];
  for (int i = 0; i <= 1000000; i++) {
    D[i] = -1;
  }

  D[1] = 0;

  for (int i = 2; i <= n; i++) {
    if (i % 3 == 0) {
      D[i] = D[i / 3] + 1;
    }
    if (i % 2 == 0) {
      if (D[i] != -1)
        D[i] = min(D[i / 2] + 1, D[i]);
      else
        D[i] = D[i / 2] + 1;
    }

    if (D[i] != -1) {
      D[i] = min(D[i - 1] + 1, D[i]);
    } else {
      D[i] = D[i - 1] + 1;
    }
  }

  cout << D[n] << endl;
}
