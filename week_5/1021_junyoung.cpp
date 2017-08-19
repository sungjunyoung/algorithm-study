//
// Created by 성준영 on 2017. 8. 1..
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define left 0
#define right 1

int getMinDirection(vector<int> q, int findNum) {
    int size = static_cast<int>(q.size() - 1);
    int findNumIndex = 0;
    for (int i = 1; i <= size; i++) {
        if (q[i] == findNum) {
            findNumIndex = i;
            break;
        }
    }

    if (size - findNumIndex + 1 > findNumIndex - 1) { // 왼쪽으로 회전하는게 더 나음
        return left;
    } else if(size - findNumIndex + 1 < findNumIndex - 1){ //오른쪽으로 회전하는게 더 나음
        return right;
    }
}

void moveLeft(vector<int> &q) {
    int first = q[1];
    for (int i = 2; i <= q.size() - 1; i++) {
        q[i - 1] = q[i];
    }
    q[q.size() - 1] = first;
}

void moveRight(vector<int> &q) {
    int last = q[q.size() - 1];
    for (int i = q.size() - 1; i > 1; i--) {
        q[i] = q[i - 1];
    }
    q[1] = last;
}

int main() {
    int n, m;
    cin >> n >> m;

    // 회전하는 큐
    vector<int> q(static_cast<unsigned long>(n + 1));
    for (int i = 1; i <= n; i++) {
        q[i] = i;
    }

    // 찾으려는 숫자들
    queue<int> findNums;
    for (int i = 1; i <= m; i++) {
        int temp;
        cin >> temp;
        findNums.push(temp);
    }


    int result = 0;
    for (int i = 1; i <= m; i++) {
        int findNum = findNums.front();
        findNums.pop();

        int direction = getMinDirection(q, findNum);

        if (direction == left) {
            while (q[1] != findNum) {
                moveLeft(q);
                result++;
            }
            q.erase(q.begin() + 1);
        } else {
            while (q[1] != findNum) {
                moveRight(q);
                result++;
            }
            q.erase(q.begin() + 1);
        }
    }

    cout << result;


}
