#include <iostream>

using namespace std;

int selfNum(int prev);

int main()
{
	int num=1;

	int arr[10001] = {0};
	for (int i = 1; i <= 10000; i++) {
		arr[selfNum(i)] = 1;
	}
	for (int i = 1; i <= 10000; i++) {
		if (arr[i] == 0)cout << i << endl;
	}

	return 0;
}

int selfNum(int prev)
{
	int next;
	next = prev;
	while (prev!=0)
	{
		next+=prev % 10;
		prev /= 10;
	}
	return next;
}