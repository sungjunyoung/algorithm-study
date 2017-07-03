//
// Created by MAC on 2017. 7. 2..
//

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

int main() {
    int input;
    int check;
    cin >> input;
    check = (input == 8) ? 9 : 0;
    for (int i = 2; i <= 8; i++) {
        cin >> input;
        if (input != abs(i - check))
            check = -1;
    }
    switch (check) {
        case 0 :
            cout << "ascending";
            break;
        case 9 :
            cout << "descending";
            break;
        default:
            cout << "mixed";
            break;
    }
    return 0;
}