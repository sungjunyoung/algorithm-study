#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int memo[101][101][101];

int recursive(vector<int> input) {
    // 다 1씩 차이나면 리턴 0)
    if(input[1] - input[0] == 1 && input[2] - input[1] == 1){
        return 0;
    }

    if(memo[input[0]][input[1]][input[2]] != 0){
        return memo[input[0]][input[1]][input[2]];
    }

    int firstMax = 0;
    for (int i = input[0] + 1; i < input[1]; i++) {
        vector<int> temp = input;
        temp[2] = temp[1];
        temp[1] = i;
        int res = recursive(temp);
        if (firstMax < res) {
            firstMax = res;
        }
    }
    int secondMax = 0;
    for (int i = input[1] + 1; i < input[2]; i++) {
        vector<int> temp = input;
        temp[0] = temp[1];
        temp[1] = i;
        int res = recursive(temp);
        if (secondMax < res) {
            secondMax = res;
        }
    }

    memo[input[0]][input[1]][input[2]] = max(firstMax, secondMax) + 1;
    return memo[input[0]][input[1]][input[2]];
}

int main() {
    vector<int> input;
    input.resize(3);
    for (int i = 0; i < 3; i++) {
        cin >> input[i];
    }

    sort(input.begin(), input.end());

    cout << recursive(input) << endl;
}
