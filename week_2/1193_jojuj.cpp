#include <iostream>
using namespace std;

int main()
{
    int input;
    cin>>input;

    int shell = 0;
    while (input > 0)
    {
        shell++;
        input -= shell;
    }

    if(shell % 2 == 0)
        cout<<input + shell<<'/'<<-input + 1;
    else
        cout<<-input + 1<<'/'<<input + shell;

    return 0;
}
