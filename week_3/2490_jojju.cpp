#include <iostream>
using namespace std;

int main()
{
    bool a,b,c,d;
    int sum;
    for (int i = 0; i < 3; ++i) {
        cin >> a >> b >> c >> d;
        sum = a+b+c+d;
        if(sum == 0)    cout<<"D"<<endl;
        else if(sum == 1)   cout<<"C"<<endl;
        else if(sum == 2)   cout<<"B"<<endl;
        else if(sum == 3)   cout<<"A"<<endl;
        else cout<<"E"<<endl;
    }
    return 0;
}