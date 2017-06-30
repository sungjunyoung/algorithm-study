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
/*
 #include <iostream>
using namespace std;
char result_arr[7000][14000];
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <2 * N-1; j++)
			result_arr[i][j] = ' ';
	}

	result_arr[0][N-1] = '*';
	result_arr[1][N-2] = '*';
	result_arr[1][N ] = '*';
	for (int i = 0; i < 5; i++)
		result_arr[2][N- 3 + i] = '*';

	if(N>=6)
	{
		int cnt = 1;
		for (int i = 6; i <= N; i *= 2)
		{
			for (int j = 0; j < i / 2; j++)
			{
				for (int k = N -1 - i / 2 ; k < N + i / 2 ; k++)
				{
					result_arr[i / 2 + j][k - i / 2 ] = result_arr[j][k];
					result_arr[i / 2 + j][k + i / 2 ] = result_arr[j][k];
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j< 2 * N-1; j++)
			cout << result_arr[i][j];
		if (i < N - 1)
			cout << " ";
		cout << endl;
	}
	return 0;
}
 */