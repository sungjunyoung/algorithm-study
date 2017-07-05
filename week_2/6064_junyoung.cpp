#include <iostream>

using namespace std;

int gcd(int a, int b) {
    return a % b ? gcd(b, a % b) : b;
}

int main() {
    int t;
    cin >> t;

    int m, n, x, y;
    int count;

    while (t--) {
        cin >> m >> n >> x >> y;

        // m, n 의 최소공배수
        int lcm = m * n / gcd(m, n);

        count = 0;
        bool flag = false;
        for (int i = x; i <= lcm; i += m) {
            if(i % y == 0 && n == y){
                cout << i << endl;
                flag = true;
                break;
            }
            if (i % n == y) {
                cout << i << endl;
                flag = true;
                break;
            }
        }

        if (!flag) {
            cout << -1 << endl;
        }
    }
}