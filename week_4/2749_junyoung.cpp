#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    int mod = 1000000;
    int cycle = mod / 10 * 15;

    vector<int> fibo(cycle + 1);
    fibo[1] = 1;
    fibo[2] = 1;
    for (int i = 3; i <= cycle; i++) {
        fibo[i] = (fibo[i - 2] + fibo[i - 1]) % mod;
    }
    cout << fibo[n % cycle] << endl;

}

