#include <iostream>
using namespace std;

int main() {

    bool array[10001] = {false};

    int tmp;
    int tmpPiece;
    int sum;

    for (int i = 1; i < 10000; ++i) {
        sum = tmp = i;
        while (tmp > 0) {
            tmpPiece = tmp % 10;
            tmp = tmp / 10;
            sum += tmpPiece;
        }
        if(sum>10000) continue;

        array[sum] = true;
    }

    for (int i = 1; i <= 10000; ++i) {
        if (!array[i]) cout << i << endl;
    }

    return 0;
}

