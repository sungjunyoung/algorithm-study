#include <iostream>
#include <vector>

using namespace std;
#define MAX_WEIGHT 10000

int inputCoinNum;
int inputMaxWeight;

int table[MAX_WEIGHT + 1];

int main() {
    cin >> inputCoinNum >> inputMaxWeight;

    int inputCoin;
    vector<int> coins;
    coins.push_back(0);

    for (int i = 1; i <= inputCoinNum; ++i) {
        cin >> inputCoin;
        coins.push_back(inputCoin);
    }

    table[0] = 1;
    for (int coinNumber = 0; coinNumber <= inputCoinNum; ++coinNumber) {
        for (int curWeight = 1; curWeight <= inputMaxWeight; ++curWeight) {
            if (curWeight - coins[coinNumber] >= 0)
                table[curWeight] += table[curWeight - coins[coinNumber]];
        }
    }

    cout << table[inputMaxWeight] << endl;

    return 0;
}