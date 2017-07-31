#include <iostream>
using namespace std;

#define MAX 1000000
int sumArray[MAX + 1];

int main() {
    int N;
    cin >> N;

    int num = 1;
    int digit;
    int sum = 0;
    int tempNum;

    for (int i = 0; i < MAX + 1; ++i)
        sumArray[i] = MAX;

    while (sum<1000000) {
        tempNum = num;
        sum = num;
        while (tempNum > 0) {
            digit = tempNum % 10;
            tempNum = tempNum / 10;
            sum += digit;
        }
        sumArray[sum] = min(sumArray[sum] , num);
        num++;
    }

    if(sumArray[N] == MAX)
        cout<<0<<endl;
    else
        cout<<sumArray[N]<<endl;

    return 0;
}