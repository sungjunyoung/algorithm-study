#include <iostream>

#define MAX_N 1000
using namespace std;

bool neighbor[MAX_N + 1][MAX_N + 1];
int N;

void countGroup(int i) {
    if (neighbor[i][0]) return;
    neighbor[i][0] = true;

    for (int j = 0; j <= N; ++j) {
        if (neighbor[i][j])
            countGroup(j);
    }
    return;
}


int main() {
    int testCase;
    cin >> testCase;
    int input;
    int groupNum;
    while (testCase--) {
        cin >> N;
        groupNum = 0;
        for (int i = 1; i <= N; ++i) {
            cin >> input;
            neighbor[i][input] = neighbor[i][input] = true;
        }

        for (int i = 1; i <= N; ++i) {
            if (!neighbor[i][0]) {
                countGroup(i);
                groupNum++;
            }
        }
        cout << groupNum << endl;

        for (int i = 0; i <= N; ++i)
            for (int j = 0; j <= N; ++j)
                neighbor[i][j] = false;

    }

    return 0;
}