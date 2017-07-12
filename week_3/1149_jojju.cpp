#include <iostream>
using namespace std;
#define MAX_N 1000

int input[MAX_N + 1][3];
int E[MAX_N + 1][3];

int getMin(int a, int b)
{
    if(a<b)     return a;
    return b;
}

int main()
{
    int n;
    cin>>n;

    for (int i = 1; i <= n; ++i) {
        for (int rgb = 0; rgb < 3; ++rgb) {
            cin >> input[i][rgb];
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int rgb = 0; rgb < 3; ++rgb) {
            if(i == 1)
                E[i][rgb] = input[i][rgb];
            else
            {
                if(rgb == 0)
                    E[i][rgb] = getMin(E[i - 1][1],E[i - 1][2]) + input[i][rgb];
                else if(rgb == 1)
                    E[i][rgb] = getMin(E[i - 1][0],E[i - 1][2]) + input[i][rgb];
                else
                    E[i][rgb] = getMin(E[i - 1][0],E[i - 1][1]) + input[i][rgb];
            }
        }
    }

    cout<<getMin(getMin(E[n][0],E[n][1]),E[n][2]);

    return 0;
}