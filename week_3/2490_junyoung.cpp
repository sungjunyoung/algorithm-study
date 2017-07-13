//
// Created by 성준영 on 2017. 7. 13..
//

#include <iostream>

using namespace std;

int main() {
    for (int i = 1; i <= 3; i++) {
        int counter = 0;
        for (int j = 1; j <= 4; j++) {
            int temp;
            cin >> temp;
            if(temp == 0) counter ++;
        }
        if(counter == 0){
            cout << "E" << endl;
        } else if(counter == 1){
            cout << "A" << endl;
        } else if (counter == 2){
            cout << "B" << endl;
        } else if(counter == 3) {
            cout << "C" << endl;
        } else if(counter == 4) {
            cout << "D" << endl;
        }
    }
}