#include <iostream>
#include <algorithm>
using namespace std;
int	a[5000000];
int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", &a[i]);
	nth_element(a, a + K - 1, a + N);
	printf("%d\n", a[K - 1]);
	return 0;
}