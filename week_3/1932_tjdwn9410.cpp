//
// Created by MAC on 2017. 7. 10..
//

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    int N;
    int arr[510][510];
    int res[510][510]={0,};
    cin>>N;
    for(int i = 1 ; i <=N ;i++)
    {
        for(int j=1;j<=i;j++)
            cin>>arr[i][j];
    }
    res[1][1]=arr[1][1];
    for(int i =2 ;i <=N; i++)
    {
        for(int j=1;j<=i;j++)
        {
            res[i][j] = (res[i-1][j-1] > res[i-1][j])?res[i-1][j-1]:res[i-1][j];
            res[i][j] +=arr[i][j];
        }
    }
    int max=0;

    for(int i = 1 ; i <=N ;i++)
    {
        if(res[N][i]>max)
            max= res[N][i];
    }
    cout<<max<<endl;
    return 0;
}