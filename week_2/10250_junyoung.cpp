//
// Created by 성준영 on 2017. 7. 02..
//


#include <iostream>

using namespace std;

void resultPrint(int XX, int YY){
    string stringYY = to_string(YY);
    string resultYY = "0";
    if(stringYY.length() == 1){
        resultYY.append(stringYY);
    } else {
        resultYY = stringYY;
    }
    string result = to_string(XX) + resultYY;
    cout << result << endl;
}

int main() {
    int t;
    int h, w, n;
    cin >> t;

    while (t--) {
        cin >> h >> w >> n;

        // 높이만큼 계속 높여준다.
        int heightIter = 0;
        // 몇번 돌았는지 카운터
        int counter = 0;
        while (heightIter < n) {
            heightIter += h;
            counter++;
        }
        // 한번 더 돈거 원복
        heightIter -= h;
        int more = n - heightIter;


        resultPrint(more, counter);
    }
}