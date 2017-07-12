//
// Created by MAC on 2017. 7. 10..
//

#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int resultArr[50][2];
    resultArr[0][0]=1;
    resultArr[0][1]=0;
    // fibo(0)
    resultArr[1][0]=0;
    resultArr[1][1]=1;
    // fibo(1)
    for(int i = 2;i<=40;i++) {
        resultArr[i][0]=resultArr[i-2][0]+ resultArr[i-1][0];
        resultArr[i][1]=resultArr[i-2][1]+ resultArr[i-1][1];
    }
    int T;
    cin>>T;
    for(int i = 0 ; i <T ;i++)
    {
        int N;
        cin>>N;
        cout<<resultArr[N][0]<<" "<<resultArr[N][1]<<endl;
    }
    return 0;
}