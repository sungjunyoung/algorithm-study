#include <iostream>
using namespace std;
#define MAX_LENGHT 1000

int cache[MAX_LENGHT + 1][MAX_LENGHT + 1];
string string1;
string string2;

int recursive(int point1, int point2) {

    if(point1 == string1.size() || point2 == string2.size())  return 0;

    if(cache[point1][point2])   return cache[point1][point2];

    int ret = -1;

    for (int curPoint1 = point1; curPoint1 < string1.size(); ++curPoint1)
        if(string2[point2] == string1[curPoint1])
            ret = max(ret, recursive(curPoint1 + 1, point2 + 1) + 1);

    return cache[point1][point2] = max(ret, recursive(point1, point2 + 1));
}

int main()
{
    cin >> string1 >> string2;
    cout<<recursive(0, 0)<<endl;
    return 0;
}