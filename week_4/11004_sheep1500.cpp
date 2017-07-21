#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	int n, k;

	scanf("%d", &n); scanf("%d", &k);

	std::vector<int> myvector;
	for (int i = 1; i <= n; i++) {
		int num;
		scanf("%d", &num);
		myvector.push_back(num);
	}
	sort(myvector.begin(), myvector.end());
	printf("%d", myvector[k - 1]);
	return 0;
}
