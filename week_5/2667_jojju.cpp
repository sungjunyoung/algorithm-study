#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 25
int num, ret;
int table[MAX + 1][MAX + 1];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int dfs(int y, int x, int count) {

    table[y][x] = 0;
    int movedX, movedY;
    for (int i = 0; i < 4; ++i) {
        movedX = x + dx[i];
        movedY = y + dy[i];
        if (movedX >= 0 && movedX < num && movedY >= 0 && movedY < num) {
            if (table[movedY][movedX] == 1) {
                count = max(count, dfs(movedY, movedX, count + 1));
            }
        }
    }
    return count;
}

int main() {

    cin >> num;
    char input;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            cin >> input;
            table[i][j] = input - '0';
        }
    }

    vector<int> array;
    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j) {
            if (table[i][j] == 1) {
                array.push_back(dfs(i, j, 1));
                ret++;
            }
        }
    }

    sort(array.begin(), array.end());
    cout << ret << endl;
    for (int i = 0; i < array.size(); ++i)
        cout << array[i] << endl;

    return 0;
}