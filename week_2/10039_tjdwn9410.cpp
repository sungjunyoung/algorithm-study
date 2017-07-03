//
// Created by MAC on 2017. 7. 2..
//

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int result = 0;
    for (int i = 0; i < 5; i++) {
        int tmp;
        cin >> tmp;
        result += (tmp < 40) ? 40 : tmp;
    }
    cout << result / 5 << endl;
    return 0;
}