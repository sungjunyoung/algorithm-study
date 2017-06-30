//
// Created by MAC on 2017. 6. 30..
//
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
int input;
char output[4000][8000];
int rec(int x ,int y, int size);
int main()
{
    cin >> input;
    for(int i = 1 ; i <= input ; i++) {
        for (int j = 1; j <= input * 2; j++)
            output[i][j] = ' ';
    }
    rec(1,input,input);
    for(int i = 1 ; i <= input ; i++)
    {
        for(int j = 1 ; j<= input*2 ; j++)
            cout<<output[i][j];
        cout<<endl;
    }
    return 0;
}
int rec(int x,int y, int size)
{
    if(size>3)
    {
        rec(x, y, size / 2);
        if(x+size/2 <= input)
        {
            rec(x + size / 2, y - size / 2, size / 2);
            rec(x + size / 2, y + size / 2, size / 2);
        }
    }
    if(size == 3)
    {
        output[x][y]='*';
        output[x+1][y+1]='*';
        output[x+1][y-1]='*';
        for(int i=-2;i<=2;i++)
            output[x+2][y+i]='*';
    }
}