//
// Created by MAC on 2017. 7. 3..
//

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int getRoom(int _H, int _W, int _N);

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int H, W, N;
        cin >> H >> W >> N;
        cout << getRoom(H, W, N) << endl;
    }
    return 0;
}

int getRoom(int _H, int _W, int _N) {
    int res;
    res = (_N % _H == 0) ? _H : _N % _H;
    res *= 100;
    res += (_N % _H == 0) ? _N / _H : _N / _H + 1;
    return res;
}