#include <iostream>
using namespace std;
#define MAX_DEPTH 500
int map[MAX_DEPTH + 1][MAX_DEPTH + 1];
int cache[MAX_DEPTH + 1][MAX_DEPTH + 1];
int depth;

int getMax(int a, int b)
{
    if(a>b) return a;
    return b;
}

int recursiveSum(int curDepth, int x) {

    if(curDepth == depth)  return map[depth][x];

    if(cache[curDepth][x])
        return cache[curDepth][x];

    return cache[curDepth][x] = map[curDepth][x] + getMax(recursiveSum(curDepth + 1, x),recursiveSum(curDepth + 1, x + 1));
}

int main()
{
    cin >> depth;

    for (int i = 1; i <= depth; ++i)
        for (int j = 1; j <= i; ++j)
            cin>>map[i][j];

    cout<<recursiveSum(1,1)<<endl;

    return 0;
}