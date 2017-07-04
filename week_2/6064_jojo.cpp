#include <iostream>
#include <math.h>

using namespace std;

int gcd(int x, int y) {
    if (x%y == 0) return y;
    else return gcd(y,x%y);
}

int main() {
    int testCase;
    cin >> testCase;

    int M;
    int N;
    int x;
    int y;

    while(testCase--)
    {
        bool ok = false;
        cin>>M>>N>>x>>y;
        int max = M * N /gcd(M,N);

        for (int i = x; i <= max; i += M) {
            if(( i % N == y || (y == N && i % y == 0) ))
            {
                ok = true;
                cout<<i<<endl;
                break;
            }
        }

        if(!ok)
            cout<<-1<<endl;
    }
    return 0;
}
