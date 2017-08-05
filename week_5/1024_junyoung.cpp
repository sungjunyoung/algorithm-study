//
// Created by 성준영 on 2017. 8. 2..
//

#include <iostream>
#include <cmath>

using namespace std;

bool isInt(double a) {
    double absolute = abs(a);
    return a == floor(a);
}

int main() {
    int n, l;
    cin >> n >> l;

    double a;
    int length = 1;
    int sum = 0;
    bool check = true;
    while (true) {
        a = double(n - sum) / double(length);

        // a 의 결과가 0보다 작거나 같으면 넘어감
        if (a < 0) {
            check = false;
            break;
        }

        // 길이가 100 이 넘어가면 false
        if (length > 100) {
            check = false;
            break;
        }

        // a 가 정수이고, 길이가 l 이상이라면
        if (isInt(a) && length >= l) {
            break;
        }

        sum += length;
        length++;

    }

    if (!check) {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (i == length - 1) {
            printf("%d", int(a) + i);
        } else {
            printf("%d ", int(a) + i);
        };

    }

}