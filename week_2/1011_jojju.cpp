#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int testCase;
    cin >> testCase;
    int inputX;
    int inputY;
    int output = 0;
    while(testCase--) {
        inputX;
        inputY;
        cin >> inputX;
        cin >> inputY;

        for (int i = 1; i <= pow(2,16); i++) {

            if ( inputY - inputX <= pow(i,2)) {
                if( inputY - inputX < (pow(i,2) + pow(i - 1,2)) / 2)
                    output = (i - 1) * 2;
                else
                    output = (i - 1) * 2 + 1;
                break;
            }
        }
        cout<<output<<endl;
    }
    return 0;
}
