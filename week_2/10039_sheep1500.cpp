#include <iostream>

using namespace std;

int main()
{
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	if (a / 5 != 0 || a < 0 || a>100)cin >> a;
	if (b / 5 != 0 || b < 0 || b>100)cin >> b;
	if (c / 5 != 0 || c < 0 || c>100)cin >> c;
	if (d / 5 != 0 || d < 0 || d>100)cin >> d;
	if (e / 5 != 0 || e < 0 || e>100)cin >> e;

	if (a < 40)a = 40;
	if (b < 40)b = 40;
	if (c < 40)c = 40;
	if (d < 40)d = 40;
	if (e < 40)e = 40;

	int average = (a + b + c + d + e) / 5;
	cout << average << endl;
	return 0;
}