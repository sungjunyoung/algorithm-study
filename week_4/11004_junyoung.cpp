#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, k, a[5000001];
    cin >> n >> k;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    printf("%d", a[k - 1]);
}

