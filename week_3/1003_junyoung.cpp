#include <iostream>
using namespace std;

int zeroCount = 0;
int oneCount = 0;

int fibonacci(int n) {
  if (n == 0) {
    zeroCount++;
    return 0;
  } else if (n == 1) {
    oneCount++;
    return 1;
  } else {
    return fibonacci(n - 1) + fibonacci(n - 2);
  }
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;

    fibonacci(n);
    cout << zeroCount << " " << oneCount << endl;
    zeroCount = 0;
    oneCount = 0;
  }
}
