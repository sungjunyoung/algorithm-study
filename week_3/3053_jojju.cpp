#include <iostream>
using namespace std;

int main()
{
    double r;
    cin >> r;
    double pi = 3.14159265358979323846;
    cout << fixed;
    cout.precision(6);
    cout<<pi*r*r<<endl;
    cout<<2*r*r<<endl;
    return 0;
}