#include <iostream>
using namespace std;

#define MAX_NUM 100
int cache [MAX_NUM][MAX_NUM][MAX_NUM];

int recursiveKangarooJump(int left, int mid, int right, int depth) {

    if(right - 2 == left)   return depth;

    if(cache[left][mid][right]) return cache[left][mid][right];

    //move left node
    int ret = - 100000;
    for (int middlePoint = mid + 1; middlePoint < right; ++middlePoint)
        ret = max(ret,recursiveKangarooJump(mid, middlePoint, right, depth + 1));

    //move right node
    for (int middlePoint = left + 1; middlePoint < mid; ++middlePoint)
        ret = max(ret, recursiveKangarooJump(left, middlePoint, mid, depth + 1));

    return cache[left][mid][right] = ret;
}

int main()
{
    int left, mid, right;
    cin >> left >> mid >> right;
    cout<<recursiveKangarooJump(left, mid, right, 0)<<endl;

    return 0;
}