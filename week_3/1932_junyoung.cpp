#include <iostream>
#include <vector>
using namespace std;

int D[500][500];

int main() {
  int n;
  cin >> n;

  vector<int> *shape = new vector<int>[n];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      int temp;
      cin >> temp;
      shape[i].push_back(temp);
    }
  }

  D[0][0] = shape[0][0];
  for (int i = 1; i < n; i++) {
    for (int j = 0; j <= i; j++) {
      if (j == 0) {
        D[i][j] = D[i - 1][j] + shape[i][j];
      } else if (j == i) {
        D[i][j] = D[i - 1][j - 1] + shape[i][j];
      } else {
        D[i][j] = max(D[i - 1][j] + shape[i][j], D[i - 1][j - 1] + shape[i][j]);
      }
    }
  }

  int result = -1;
  for (int i = 0; i < n; i++) {
      if(result < D[n-1][i]){
          result = D[n-1][i];
      }
  }
  cout << result << endl;
}
