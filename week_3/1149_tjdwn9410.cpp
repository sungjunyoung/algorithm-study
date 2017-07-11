//
// Created by MAC on 2017. 7. 10..
//

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int N;
    int RGB[1010][3];
    int res[1010][3];
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++)
            cin >> RGB[i][j];
    }
    res[0][0] =RGB[0][0];
    res[0][1] =RGB[0][1];
    res[0][2] =RGB[0][2];
    //init

    for(int i = 1; i <N;i++)
    {
        for(int j=0;j<3;j++)
        {
            int tmp=2147483647;
            for(int k=0;k<3;k++)
            {
                if(j!=k)
                {
                    if(tmp > RGB[i][j] + res[i-1][k])
                        tmp = RGB[i][j] + res[i-1][k];
                }
            }
            res[i][j]= tmp;
        }
    }
//    for(int i = 0; i <N;i++) {
//        for (int j = 0; j < 3; j++) {
//            cout << res[i][j] << " ";
//        }
//        cout << endl;
//    }
    int min=2147483647;
    for(int i = 0 ; i < 3 ;i++)
    {
        if(res[N-1][i] <min)
            min=res[N-1][i];
    }
    cout<<min<<endl;
    return 0;
}