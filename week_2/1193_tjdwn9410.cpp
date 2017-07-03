//
// Created by MAC on 2017. 7. 3..
//

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int N;
    cin >> N;
    int bound = 0;
    for (int i = 1;; i++) {
        bound += i;
        if (N <= bound) {
            int resP, resQ;
            int diff = bound - N ;
            resP = ( i % 2 == 0) ? i - diff : 1 + diff;
            resQ = ( i % 2 == 0) ? 1 + diff : i - diff;
            cout << resP << "/" << resQ << endl;
            break;
        }
    }
    return 0;
}