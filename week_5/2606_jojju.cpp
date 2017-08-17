#include <iostream>
using namespace std;
#define MAX 100
int num, pairNum, ret;
bool pairTable[MAX + 1][MAX + 1];

void recursive(int curPoint) {
    pairTable[curPoint][0] = true;
    ret++;
    for (int i = 1; i <= num; ++i) {
        if(pairTable[curPoint][i] && !pairTable[i][0])
            recursive(i);
    }
}

int main()
{
    cin >> num >> pairNum;
    int a, b;
    for (int i = 0; i < pairNum; ++i) {
        cin >> a >> b;
        pairTable[a][b] = pairTable[b][a] = true;
    }
    recursive(1);
    cout<<ret - 1<<endl;

    return 0;
}