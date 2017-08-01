//
// Created by 성준영 on 2017. 8. 1..
//

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int result;
    cin >> result;

    int stick = 64;
    int smallest = 64;
    int stickCount = 1;
    while (stick != result) {
        smallest /= 2;
        if(stick - smallest >= result){
            stick -= smallest;
        } else {
            stickCount ++;
        }
    }

    cout << stickCount ;
}