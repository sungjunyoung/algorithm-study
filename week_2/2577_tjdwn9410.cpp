//
// Created by MAC on 2017. 7. 2..
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int multiRes = 1;
    int resultArr[10] = {0};
    for (int i = 0; i < 3; i++) {
        int tmp;
        cin >> tmp;
        multiRes *= tmp;
    }
    while (multiRes > 0) {
        resultArr[multiRes % 10]++;
        multiRes /= 10;

    }
    for (int i = 0; i < 10; i++) {
        cout << resultArr[i] << endl;
    }
    return 0;
}
