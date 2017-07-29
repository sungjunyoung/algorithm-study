#include <iostream>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;
    int * array = new int [N];

    for (int i = 0; i < N; ++i)
        cin >> array[i];

    for (int i = 0; i < N; ++i)
    {
        if(array[i] < X)
            cout << array[i]<<' ';
    }

    return 0;
}