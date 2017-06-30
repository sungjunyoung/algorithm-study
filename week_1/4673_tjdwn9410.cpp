#include <iostream>
using std::cout;
using std::endl;
int visit[11000];
void checkSelfNumber(int N);
int getSum(int N);
int main() {
    for(int i = 1 ; i <= 10000; i++ )
    {
        if(visit[i]==0) {
            checkSelfNumber(i);
            cout << i << endl;
        }
    }
    return 0;
}
void checkSelfNumber(int N)
{
    int res = getSum(N);
    if(res>10000 || visit[res] == 1) // 10000이 넘었거나 이미 check되어 있으면 더 이상 확인하지 않음
        return;
    visit[res]=1;
    checkSelfNumber(res);
} // self number 확인

int getSum(int N)
{
    int temp =N;
    int sum =N;
    while(temp!=0)
    {
        sum+=temp%10;
        temp=temp/10;
    }//다음 값을 구하기 위해 자리수를 더함
    return sum;
}