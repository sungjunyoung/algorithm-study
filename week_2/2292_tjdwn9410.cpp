//
// Created by MAC on 2017. 7. 3..
//

#include<iostream>
using std::cout;
using std::endl;
using std::cin;
int main()
{
    int N;
    int startValue=1;
    int res=1;
    cin>>N;
    while(N>startValue)
    {
        startValue += res*6;
        res++;
    }
    cout<<res<<endl;
    return 0;
}