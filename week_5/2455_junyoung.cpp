//
// Created by 성준영 on 2017. 8. 1..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int max = 0;

    for (int i = 1; i <= 4; i++) {
        int out, in;
        cin >> out >> in;
        int temp = max;
        temp -= out;
        temp += in;
        if (max < temp) {
            max = temp;
        }
    }
    cout << max;
}