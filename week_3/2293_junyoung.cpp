#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins;

    for (int i = 1; i <= n; i++) {
        int tempCoin;
        cin >> tempCoin;
        coins.push_back(tempCoin);
    }
    sort(coins.begin(), coins.end());

    long long int D[10001];
    for (int i = 1; i <= 10000; i++) {
        D[i] = 0;
    }

    D[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= k; j++) {
            if(j-coins[i] >= 0){
                D[j] = D[j - coins[i]] + D[j];
            }
        }
    }

    cout << D[k] << endl;
}
