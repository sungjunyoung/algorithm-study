//
// Created by MAC on 2017. 7. 3..
//

#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int N;
    int numArr[10]={0,};
    cin>>N;
    while(N>0)
    {
        numArr[N%10]++;
        N=N/10;
    }
    numArr[6]=(numArr[6]+numArr[9])/2 + (numArr[6]+numArr[9])%2;
    numArr[9]=0;
    int max=0;
    for(int i =0; i <= 9 ;i++)
    {
        if(max<numArr[i])
            max=numArr[i];
    }
    cout<<max<<endl;
    return 0;
}