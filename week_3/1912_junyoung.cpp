#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> numbers;
    vector<int> D;
    numbers.resize((unsigned long) (n + 1));
    D.resize((unsigned long) (n + 1));

    for (int i = 1; i <= n; i++) {
        cin >> numbers[i];
    }

    for (int i = 1; i <= n; i++) {
        if (D[i - 1] + numbers[i] > numbers[i]) {
            D[i] = D[i - 1] + numbers[i];
        } else {
            D[i] = numbers[i];
        }
    }

    int max = D[1];
    for (int i = 2; i <= n; i++) {
        if (max < D[i]) {
            max = D[i];
        }
    }

    cout << max << endl;
}

