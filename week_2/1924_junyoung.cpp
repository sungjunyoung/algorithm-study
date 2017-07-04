//
// Created by 성준영 on 2017. 7. 02..
//

#include <iostream>

using namespace std;

int main() {
    int m, d;
    cin >> m >> d;

    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 월별 날짜

    int daysCounter = 0;
    for (int i = 1; i < m; i++) {
        daysCounter += months[i];
    } // 입력받은 달의 이전 달까지 날짜수
    daysCounter += d; // 입력받은 날짜수 더해주기

    int resultNum = daysCounter % 7;
    string result = "";
    switch (resultNum){
        case 0 :
            result = "SUN";
            break;
        case 1 :
            result = "MON";
            break;
        case 2 :
            result = "TUE";
            break;
        case 3 :
            result = "WED";
            break;
        case 4 :
            result = "THU";
            break;
        case 5 :
            result = "FRI";
            break;
        case 6 :
            result = "SAT";
            break;
    }
    cout << result << endl;
}