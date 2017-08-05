#include <iostream>

using namespace std;
#define MAX_LENGHT 1000
int cache[MAX_LENGHT + 1][MAX_LENGHT + 1];
string string1;
string string2;

int recursive(int point1, int point2) {

    if (point1 == string1.size() || point2 == string2.size()) return 0;

    if (cache[point1][point2] != -1) return cache[point1][point2];

    int lcs = 0;

    if (string2[point2] == string1[point1])
        lcs = recursive(point1 + 1, point2 + 1) + 1;
    else
        lcs = max(recursive(point1, point2 + 1), recursive(point1 + 1, point2));

    return cache[point1][point2] = lcs;
}

void findString(int point1, int point2, string &output) {
    if (point1 == string1.size() || point2 == string2.size())
        return;

    if (string1[point1] == string2[point2]) {
        output += string1[point1];
        findString(point1 + 1, point2 + 1, output);
    }
    else {
        if (cache[point1][point2] == cache[point1][point2 + 1])
            findString(point1, point2 + 1, output);
        else
            findString(point1 + 1, point2, output);
    }
}

int main() {
    cin >> string1 >> string2;

    for (int i = 0; i < MAX_LENGHT + 1; ++i)
        for (int j = 0; j < MAX_LENGHT + 1; ++j)
            cache[i][j] = -1;

    cout << recursive(0, 0) << endl;

    string output = "";
    findString(0, 0, output);
    cout << output << endl;

    return 0;
}