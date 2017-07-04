#include <iostream>

using namespace std;

int main() {

    int apart[15][15] = {0};

    for (int floor = 0; floor < 15; ++floor) {
        apart[floor][1] = 1;
        for (int address = 1; address < 15; ++address) {
            apart[floor][address] = (floor == 0 ? address : apart[floor][address - 1] + apart[floor - 1][address]);
        }
    }

    int testCase;
    int inputFloor;
    int inputAddress;

    cin >> testCase;
    while (testCase--) {
        cin >> inputFloor;
        cin >> inputAddress;
        cout << apart[inputFloor][inputAddress] << endl;
    }

    return 0;
}
