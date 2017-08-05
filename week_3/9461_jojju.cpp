#include <iostream>
using namespace std;

#define MAX 100
long long num_array [MAX + 1];

int main()
{
    int testCase;
    cin>>testCase;
    int input;

    num_array[0] = 0;
    num_array[1] = 1;
    num_array[2] = 1;
    num_array[3] = 1;
    num_array[4] = 2;
    num_array[5] = 2;

    while(testCase--)
    {
        cin>>input;

        if(input < 6)
            cout<<num_array[input]<<endl;
        else {
            for (int i = 6; i <= input; ++i)
                num_array[i] = num_array[i - 1] + num_array[i - 5];

            cout<<num_array[input]<<endl;
        }
    }

    return 0;
}