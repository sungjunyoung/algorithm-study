#include <iostream>
using namespace std;

#define MAX_NUM 1000000
int cache[MAX_NUM + 1];

int recursiveOperation(int num) {

    if(num == 1)
        return 0;
    if(cache[num])
        return cache[num];

    int ret = MAX_NUM + 1;
    if(num % 3 == 0)
        ret = min(ret, recursiveOperation(num / 3));
    if(num % 2 == 0)
        ret = min(ret, recursiveOperation(num / 2));

    return cache[num]  = min(ret, recursiveOperation(num - 1)) + 1;
}

int main()
{
    int num;
    cin >> num;
    cout<<recursiveOperation(num);

    return 0;
}