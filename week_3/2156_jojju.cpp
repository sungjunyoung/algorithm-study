#include <iostream>
using namespace std;
#define MAX_N 10000

int N;
int num_array [MAX_N + 1];
int cache [MAX_N + 1][3];

int recursive(int point, int constant) {

    if(point > N || constant == 3)  return 0;

    if(cache[point][constant])  return cache[point][constant];

    int ret = max(recursive(point + 1, constant + 1), recursive(point + 2, 1));
    if(constant == 2) ret = max(ret, recursive(point + 3, 1));

    return cache[point][constant] = num_array[point] + ret;
}

int main()
{
    cin >> N;
    int input;

    for (int i = 1; i <= N; ++i) {
        cin >> input;
        num_array[i] = input;
    }

    cout<<recursive(0, 0)<<endl;

    return 0;
}