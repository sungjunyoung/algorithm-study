//
// Created by 성준영 on 2017. 7. 02..
//


#include <iostream>

using namespace std;

int main() {
    int list[9];
    for (int i = 1; i <= 8; i++) {
        cin >> list[i];
    }

    bool desc = true;
    bool asc = true;

    for (int i = 1; i <= 8; i++) {
        if (list[i] != i) {
            asc = false;
        }

        if (list[9 - i] != i) {
            desc = false;
        }
    }

    if (!asc && !desc) {
        cout << "mixed" << '\n';
    } else if (asc){
        cout << "ascending" << '\n';
    } else if (desc) {
        cout << "descending" << '\n';
    }
}