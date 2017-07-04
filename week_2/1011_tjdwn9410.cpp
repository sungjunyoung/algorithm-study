//
// Created by MAC on 2017. 7. 3..
//

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int result(int diff);

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x_in, y_in;
        cin >> x_in >> y_in;
        cout << result(y_in - x_in) << endl;
    }
    return 0;
}

int result(int diff) {
    unsigned long cnt = 1;
    unsigned long res = 1;
    while (diff > 1) {
        unsigned long highBound = cnt * cnt;
        if (diff <= highBound) {
            unsigned long lowBound = (cnt - 1) * (cnt - 1) + 1;
            if (diff < (lowBound + highBound) / 2)
                res = cnt * 2 - 2;
            else
                res = cnt * 2 - 1;
            break;
        }
        cnt++;
    }
    return res;
}