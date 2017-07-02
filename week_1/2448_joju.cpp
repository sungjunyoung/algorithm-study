#include <iostream>
using namespace std;

int N;

void recursiveStar(char **table, int depth) {
    if (depth == N) return; //기저사례

    int nextDepth = 2 * depth;  //다음으로 찍어낼 깊이
    int copyRange;  //좌우 복사 위치 구분
    for (int y = depth; y < nextDepth; ++y) {
        copyRange = depth;
        for (int x = N - nextDepth; x < N + nextDepth - 1; ++x) {
            if (x == N) copyRange = - copyRange;
            table[y][x] = table[y - depth][x + copyRange];
        }
    }
    recursiveStar(table, nextDepth);
}

int main() {
    cin >> N;

    char **table = new char *[N];
    for (int i = 0; i < N; ++i)
        table[i] = new char[2 * N - 1];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 2 * N - 1; ++j)
            table[i][j] = ' ';

    //처음 위에서부터 3칸 세팅
    for (int i = 0; i < 3; ++i)
        for (int j = N - i - 1; j < N + i; ++j)
            if (i % 3 != 1 || j != N - 1)
                table[i][j] = '*';

    //초기 깊이 3
    recursiveStar(table, 3);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2 * N - 1; ++j)
            cout << table[i][j];
        cout << endl;
    }

    return 0;
}


