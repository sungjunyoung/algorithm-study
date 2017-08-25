#include <iostream>

#define MAX 500
using namespace std;

bool table[MAX + 1][MAX + 1];
int outputArray[MAX + 1];
int teamArray[MAX + 1];

void makeTable(int size, int n) {
    if (n == 0) return;
    for (int i = n + 1; i < size; ++i)
        table[teamArray[n]][teamArray[i]] = true;
    makeTable(size, n - 1);
}

int main() {
    int testCase, n, m;
    int start, end, count;
    bool temp, ok;
    cin >> testCase;
    while (testCase--) {
        cin >> n;
        for (int i = 1; i <= n; ++i)
            cin >> teamArray[i];
        makeTable(n + 1, n - 1);

        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> start >> end;
            temp = table[start][end];
            table[start][end] = table[end][start];
            table[end][start] = temp;
        }

        ok = true;
        for (int i = 1; i < n + 1; ++i) {
            count = 0;
            for (int j = 1; j < n + 1; ++j) {
                if (table[j][i])
                    count++;
            }
            if (outputArray[count] != 0) {
                ok = false;
                break;
            }
            outputArray[count] = i;
        }

        if (ok) {
            for (int i = 0; i < n; ++i) {
                cout << outputArray[i] << ' ';
            }
            cout << endl;
        } else
            cout << "IMPOSSIBLE" << endl;

        for (int i = 0; i < n + 1; ++i) {
            for (int j = 0; j < n + 1; ++j) {
                table[i][j] = false;
            }
            outputArray[i] = 0;
            teamArray[i] = 0;
        }
    }
    return 0;
}