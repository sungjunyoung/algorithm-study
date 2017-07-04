//
// Created by MAC on 2017. 7. 3..
//
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int pascal[20][20];
    for (int i = 0; i <= 15; i++) {
        pascal[0][i]=1;
        pascal[i][0]=1;
    }
    for (int i = 1; i <= 15; i++) {
        for (int j = 1; j <= 15; j++) {
            pascal[i][j] = pascal[i][j - 1] + pascal[i - 1][j];
        }
    }
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        int k,n;
        cin>>k>>n;
        cout<<pascal[k+1][n-1]<<endl;
    }
}
