#include <iostream>

using namespace std;

int main() {
    int testCase;
    cin>>testCase;

    int H;
    int W;
    int customer;
    while (testCase--) {
        cin >> H >> W >> customer;
        int front = ((customer % H == 0) ? H : customer % H) * 100;
        int back =  (customer % H == 0) ? (customer / H) : (customer / H) + 1;
        cout << front + back << endl;
    }

    return 0;
}