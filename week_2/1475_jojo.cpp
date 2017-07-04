#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    int setArray [9] = {0};

    int tmp = N;
    int piece = 0;
    while(tmp > 0)
    {
        piece = tmp % 10;
        tmp = tmp / 10;

        if(piece == 9)
            setArray[6]++;
        else
            setArray[piece]++;
    }
    setArray[6] = (setArray[6] + 1)/ 2;
    int max = -1;
    for (int i = 0; i < 9; ++i) {
        if(max < setArray[i])
            max = setArray[i];
    }
    cout<<max<<endl;

    return 0;
}
