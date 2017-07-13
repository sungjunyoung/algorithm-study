#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int input;

    int sum = 0;
    bool isallMinus = true;

    int ifallMinus = -2147483647;
    int ret = -2147483647;

    for (int i = 0; i < n; ++i) {
        cin>>input;
        ifallMinus = max(input, ifallMinus);

        if (input > 0)  isallMinus = false;

        sum = input + sum > 0 ? input + sum : 0;
        ret = max(ret, sum);
    }

    if(isallMinus)
        cout<<ifallMinus;
    else
        cout << ret;

    return 0;
}