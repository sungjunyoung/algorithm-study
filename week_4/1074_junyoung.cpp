//
// Created by 성준영 on 2017. 7. 21..
//

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

long long int n, r, c;

bool result = false;

int moveX[4] = {0, 0, 1, 1};
int moveY[4] = {0, 1, 0, 1};

long long int
recursiveCircuit(long long int x, long long int y, long long int size) {
    if (size == 2) {
        long long int tempX, tempY;
        for (int i = 0; i < 4; ++i) {
            tempX = x + moveX[i];
            tempY = y + moveY[i];

            if (tempX == r && tempY == c) {
                result = true;
                return i + 1;
            }
        }
        return 4;
    } else {
        int count = 0;
        if (!result)
            count += recursiveCircuit(x, y, size / 2); //왼위
        if (!result)
            count += recursiveCircuit(x, y + size / 2, size / 2); //오위
        if (!result)
            count += recursiveCircuit(x + size / 2, y, size / 2); //왼아
        if (!result)
            count += recursiveCircuit(x + size / 2, y + size / 2, size / 2); //오아
        return count;
    }
}

int main() {
    cin >> n >> r >> c;

    cout << recursiveCircuit(0, 0, (long long int) pow(2, n)) - 1 << endl;

}
