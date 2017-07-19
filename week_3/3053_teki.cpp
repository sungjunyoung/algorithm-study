#include <iostream>
using namespace std;
#define PI       3.14159265358979323846
int main()
{
	int R;
	cin >> R;
	cout << fixed;
	cout.precision(6);
	cout << (double)((R*R)*PI) << endl;
	cout<<(double)(2 * R*R);
	return 0;
}