//
// Created by MAC on 2017. 7. 3..
//

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int calcYear(int _M, int _N, int _x, int _y);

int GCD(int n1, int n2);

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        cout << calcYear(M, N, x, y)<<endl;
    }
    return 0;
}

int calcYear(int _M, int _N, int _x, int _y) {
    int maxYear = _M*_N/GCD(_M,_N);
    int res =_x;
    while(res <= maxYear)
    {
        if(res% _N == _y || (res% _N == 0 && _y ==_N))
            return res;
        res += _M;
    }
    return -1;
}

int GCD(int n1, int n2) {
    if (n1 % n2 == 0)return n2;
    else return GCD(n2, n1 % n2);
}