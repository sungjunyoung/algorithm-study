#include <iostream>

using namespace std;

#define MAX 100
int table[MAX + 1][MAX + 1];
long long cache[MAX + 1][MAX + 1];
int N;

long long recursive(int y, int x) {
    if (y == N - 1 && x == N - 1) return 1;

    int distance = table[y][x];

    if(distance == 0)   return 0;
    if(cache[y][x] != -1)   return cache[y][x];

    long long ret = 0;
    if (y + distance < N)
        ret += recursive(y + distance, x);
    if (x + distance < N)
        ret += recursive(y, x + distance);

    return cache[y][x] = ret;
}

int main() {
    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> table[i][j];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cache[i][j] = -1;

    cout << recursive(0, 0) << endl;

    return 0;
}