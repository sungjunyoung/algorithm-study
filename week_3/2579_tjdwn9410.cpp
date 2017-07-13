//
// Created by MAC on 2017. 7. 10..
//

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int max(int arg1,int arg2);
int main() {
    int N;
    int stair[310];
    int arr[310][2];
    cin >>N;
    for(int i = 1 ; i <=N; i++)
        cin>>stair[i];
    arr[0][0] = 0;
    arr[0][1] = 0;

    arr[1][0]= stair[1];
    arr[1][1]= stair[1];

    for(int i = 2; i<=N;i++)
    {
        arr[i][0] = stair[i] + arr[i-1][1];
        arr[i][1] = stair[i] + max(arr[i-2][0], arr[i-2][1]);
    }
    cout<<max(arr[N][0],arr[N][1])<<endl;
    return 0;
}

int max(int arg1,int arg2)
{
    if(arg1>arg2)
        return arg1;
    return arg2;
}