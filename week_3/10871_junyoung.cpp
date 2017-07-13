//
// Created by 성준영 on 2017. 7. 13..
//

#include <iostream>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
        int test;
        cin >> test;
        if(test < x){
            cout << test << " ";
        }
    }
}