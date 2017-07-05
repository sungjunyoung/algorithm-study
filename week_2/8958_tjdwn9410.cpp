//
// Created by MAC on 2017. 7. 2..
//

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
int main()
{
    int N;
    char testCase[85];
    cin >>N;
    for(int i=0; i < N; i++)
    {
        int resultArr[85];
        int sum=0;
        cin>>testCase;
        sum = resultArr[0] = (testCase[0] == 'O')?1:0;
        for(int j=1;j<strlen(testCase);j++) {
            resultArr[j] = (testCase[j] == 'O') ? resultArr[j - 1] + 1 : 0;
            sum+=resultArr[j];
        }
        cout<<sum<<endl;
    }
    return 0;
}