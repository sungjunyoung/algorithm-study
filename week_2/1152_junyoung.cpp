//
// Created by 성준영 on 2017. 7. 02..
//

#include <iostream>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    int count = 1;
    // 띄워쓰기 개수로 단어 개수 파악. 첫번째, 마지막 띄워쓰기는 포함하지 않음
    for (int i = 1; i < input.length() - 1; i++) {
        if (input[i] == ' ') {
            count++;
        }
    }

    // 단어 개수가 하나로 나오는 경우, 하나의 띄워쓰기라면 count = 0, 오직 한 단어로 되어있다면 넘어감
    if (count == 1) {
        if (input == " ") {
            count = 0;
        }
    }

    cout << count << endl;
}