#include <iostream>
using namespace std;

int main()
{
    bool ascending = true;
    bool descending = true;

    int input = 0;
    int preInput = 0;
    for (int i = 0; i < 8; ++i) {
        cin>>input;
        if(i>0)
        {
            if(input > preInput)
                descending = false;
            else if(input < preInput)
                ascending = false;
        }
        preInput = input;
    }

    if(ascending)
        cout<<"ascending";
    else if(descending)
        cout<<"descending";
    else
        cout << "mixed";

    return 0;
}