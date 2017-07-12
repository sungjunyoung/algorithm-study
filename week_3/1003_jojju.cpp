#include <iostream>
using namespace std;

int fibonacci(int n, int & zero, int & one)
{
    if(n == 1)  {
        one++;
        return 1;
    }
    if(n == 0)  {
        zero++;
        return 0;
    }

    return fibonacci(n - 1, zero, one) + fibonacci(n - 2, zero, one);
}

int main()
{
    int testCase;
    cin>>testCase;

    int input;
    int zero;
    int one;

    while(testCase--)
    {
        zero = 0;
        one = 0;
        cin>>input;
        fibonacci(input, zero, one);
        cout<<zero<<' '<<one<<endl;
    }
    return 0;
}