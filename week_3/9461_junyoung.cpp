#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    vector<long long int> padoban;
    padoban.resize(101);
    for (int i = 1; i <= 3; i++) {
        padoban[i] = 1;
    }
    padoban[4] = 2;
    padoban[5] = 2;

    for (int i = 6; i <= 100; i++) {
        padoban[i] = padoban[i-1] + padoban[i-5];
    }

    while (t--) {
        int n;
        cin >> n;


        cout << padoban[n] << endl;
    }
}

