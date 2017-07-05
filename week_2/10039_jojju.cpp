#include <iostream>
using namespace std;

int main()
{
    int input;
    int sum = 0;
    for (int i = 0; i < 5; ++i) {
        cin>>input;
        if(input < 40)  input = 40;
        sum += input;
    }
    cout<<sum/5;

    return 0;
}