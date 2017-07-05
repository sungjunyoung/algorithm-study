//
// Created by 성준영 on 2017. 7. 02..
//


#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--){
        string OXResult;
        cin >> OXResult;

        int result = 0;
        int count = 0;
        // OXResult 만큼 돌면서 체크
        for (int i = 0; i < OXResult.length(); i++) {
            if (OXResult[i] == 'O') {
                count += 1;
                result += count;
            } else {
                count = 0;
            }
        }
        cout << result << endl;
    }
}