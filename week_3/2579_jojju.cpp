#include <iostream>
using namespace std;

#define MAX_STAIR_NUM 300
int stairs[MAX_STAIR_NUM + 1];
int cache[MAX_STAIR_NUM + 1][2];
int stairNum;

int getMax(int a, int b)
{
    if(a > b)   return a;
    return b;
}

int recursiveStair(int stair, int constant) {

    if(constant == 3 || stair > stairNum)
        return 0;
    if(stair == stairNum)
        return cache[stair][constant] = stairs[stair];
    if(cache[stair][constant])
        return cache[stair][constant];

    int upstair1 = recursiveStair(stair + 1, constant + 1);
    int upstair2 = recursiveStair(stair + 2, 1);

    int returnCurStair = stairs[stair];

    if(!upstair1 && !upstair2)
        returnCurStair = 0;

    return cache[stair][constant] = returnCurStair + getMax(upstair1, upstair2);
}

int main()
{
    cin >> stairNum;
    int input;
    stairs[0] = 0;
    for (int i = 1; i <= stairNum; ++i) {
        cin>>input;
        stairs[i] = input;
    }
    cout<<recursiveStair(0, 0);

    return 0;
}