#include <iostream>

using namespace std;
#define MAX 64
string string1[MAX + 1];

string recursiveCompress(int y, int x, int size) {
    if (size == 1) return string(1, string1[y][x]);

    size /= 2;
    string leftup = recursiveCompress(y, x, size);
    string rightup = recursiveCompress(y, x + size, size);
    string leftdown = recursiveCompress(y + size, x, size);
    string rightdown = recursiveCompress(y + size, x + size, size);

    if (leftup == rightup && rightup == leftdown && leftdown == rightdown && leftdown.size() == 1)
        return leftup;
    else
        return "(" + leftup + rightup + leftdown + rightdown + ")";
}

int main() {
    int N;
    cin >> N;

    string input;
    for (int i = 0; i < N; ++i) {
        cin >> input;
        string1[i] = input;
    }
    cout << recursiveCompress(0, 0, N);
    return 0;
}