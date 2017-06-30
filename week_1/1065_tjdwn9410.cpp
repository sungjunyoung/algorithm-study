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
    if(N>=100) { // 100 이전의 모든 숫자는 자리수별 등차수열이기 때문에 확인할 필요가 없다
        // 1~9는 한자리이기 때문에 무조건 등차수열이며 ,10~99까지는 자리수의 차이가 하나만 발생하기 때문
        int divisionArr[4]; // 각 자리수 분할
        int cnt = 0;
        while (tmp > 0) {
            divisionArr[cnt++] = tmp % 10;
            tmp /= 10;
        }
        int initValue = divisionArr[0]-divisionArr[1]; // 초기 차이값
        for (int i = 1; i < cnt - 1; i++) {
            if (initValue != divisionArr[i]-divisionArr[i+1]) { //등차인지 확인
                res = 0;
                break;
            }
        }
    }
    return res;

}