#include <iostream>
using namespace std;

int array[10];

int main()
{
    int input;
    int ret = 1;
    for (int i = 0; i < 3; ++i) {
        cin>>input;
        ret *= input;
    }

    while(ret > 0) {
        input = ret % 10;
        ret = ret / 10;
        array[input]++;
    }

    for (int i = 0; i < 10; ++i) {
        cout<<array[i]<<endl;
    }

    return 0;
}