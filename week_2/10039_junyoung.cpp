//
// Created by 성준영 on 2017. 7. 02..
//


#include <iostream>

using namespace std;

int main() {
    int scores[5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> scores[i];
        if (scores[i] < 40) scores[i] = 40;
        sum += scores[i];
    }

    cout << sum / 5 << endl;
}