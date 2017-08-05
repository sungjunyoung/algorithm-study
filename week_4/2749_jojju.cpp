#include <iostream>

using namespace std;

int main() {
    int fibonachi[1500000];
    fibonachi[0] = 0;
    fibonachi[1] = 1;

    long long N;
    cin >> N;
    for (int i = 2; i < 1500000; ++i)
        fibonachi[i] = (fibonachi[i - 1] + fibonachi[i - 2]) % 1000000;

    cout << fibonachi[N % 1500000] << endl;

    return 0;
}