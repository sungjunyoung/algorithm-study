#include <iostream>

using namespace std;

#define MAX 2200
int table[MAX + 1][MAX + 1];
int numCount[3];

int recursiveCompress(int y, int x, int size) {
    if (size == 1) {
        numCount[table[y][x] + 1]++;
        return table[y][x];
    }
    size /= 3;
    int dd[] = {0, size, size * 2};
    int digit = 0;
    int post = 0;
    bool isAllSame = true;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i + j > 0) {
                digit = recursiveCompress(y + dd[i], x + dd[j], size);
                if (post != digit) isAllSame = false;
                post = digit;
            } else {
                digit = recursiveCompress(y + dd[i], x + dd[j], size);
                post = digit;
            }
        }
    }

    if (isAllSame)
        numCount[digit + 1] -= 8;

    return 2;
}

int main() {
    int N;
    cin >> N;

    int input;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> input;
            table[i][j] = input;
        }
    }
    recursiveCompress(0, 0, N);
    cout << numCount[0] << endl;
    cout << numCount[1] << endl;
    cout << numCount[2] << endl;


    return 0;
}