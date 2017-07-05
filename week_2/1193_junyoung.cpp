//
// Created by 성준영 on 2017. 7. 02..
//


#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int iter = 1;
    int adder = 1;
    int counter = 0;
    // 한 묶음에서 1,2,3,4 씩 늘려지므로
    while (iter <= n) {
        iter += adder;
        adder += 1;
        counter++;
    }
    // 한번 더 돈거 뺴주기
    iter -= adder - 1;
    int sub = n - iter;

    int up, down;
    // 짝수 / 홀수
    if(counter%2 == 0){
        up = 1 + sub;
        down = counter - sub;
        cout << up << "/" << down << endl;
    } else {
        down = 1 + sub;
        up = counter - sub;
        cout << up << "/" << down << endl;
    }


}