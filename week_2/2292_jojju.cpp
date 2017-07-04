#include <iostream>
using namespace std;

int main()
{
    int input;
    cin>>input;

    int count = 1;
    int shell = 0;
    while (input > 1)
    {
        shell += 6;
        input -= shell;
        count++;
    }

    cout<<count;

    return 0;
}