#include <iostream>
using namespace std;

int main()
{
    int testCase;
    cin>>testCase;

    int output[testCase];

    for (int i = 0; i < testCase; ++i) {
        string oxArray;
        cin>>oxArray;

        int sequentialCount = 0;
        int accumulatedCount = 0;

            for (int ox = 0; ox < oxArray.length(); ++ox)
                sequentialCount += (accumulatedCount = (oxArray[ox] == 'O' ? accumulatedCount + 1 : 0));

        output[i] = sequentialCount;
    }

    for (int i = 0; i < testCase; ++i)
        cout<<output[i]<<endl;

    return 0;
}