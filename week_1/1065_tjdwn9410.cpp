//
// Created by MAC on 2017. 6. 30..
//
#include <iostream>
#include <math.h>
using std::cin;
using std::cout;
using std::endl;
int checkAS(int N); //arithmetic sequence
int main()
{
    int N;
    int result=0;
    cin>>N;
    for(int i = 1 ; i <=N; i++)
        result+=checkAS(i);
    cout<<result<<endl;
    return 0;
}
int checkAS(int N)
{
    int tmp =N;
    int res=1;
    if(N>=100) {
        int divisionArr[10]; // 각 자리수 분할
        int cnt = 0;
        while (tmp > 0) {
            divisionArr[cnt++] = tmp % 10;
            tmp /= 10;
        }
        int initValue = divisionArr[0]-divisionArr[1];
        for (int i = 1; i < cnt - 1; i++) {
            if (initValue != divisionArr[i]-divisionArr[i+1]) {
                res = 0;
                break;
            }
        }
    }
    return res;

}