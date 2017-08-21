#include <iostream>
#include <vector>
using namespace std;
#define MAX_POINT 3001
int neighbor[MAX_POINT + 1][MAX_POINT + 1];

struct point
{
    int x;
    int y;
    int r;
};
int getDistance(int movedX, int movedY, int x, int y) {
    return (movedX - x)*(movedX - x) + (movedY - y)*(movedY - y);
}

void countGroup(int i, int pointNum) {
    if (neighbor[i][pointNum] == 1)
        return;

    neighbor[i][pointNum] = 1;
    for (int j = 0; j < pointNum; ++j) {
        if (neighbor[i][j] == 1) {
            countGroup(j, pointNum);
        }
    }
    return;
}


int main() {
    int testCase;
    cin >> testCase;

    int pointNum;
    while (testCase--) {
        cin >> pointNum;
        vector<point> array;
        point input;
        for (int i = 0; i < pointNum; ++i) {
            cin >> input.x >> input.y >> input.r;
            array.push_back(input);
        }

        for (int i = 0; i < pointNum; ++i) {
            for (int j = 0; j < i; ++j) {
                if((array[i].r + array[j].r) * (array[i].r + array[j].r)
                   >= getDistance(array[i].x, array[i].y, array[j].x, array[j].y))
                {
                    neighbor[i][j] = 1;
                    neighbor[j][i] = 1;
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < pointNum; ++i) {
            if (neighbor[i][pointNum] == 0) {
                countGroup(i, pointNum);
                ret++;
            }
        }
        cout << ret << endl;
        for (int i = 0; i <= pointNum; ++i) {
            for (int j = 0; j <= pointNum; ++j) {
                neighbor[i][j] = 0;
            }
        }
    }
    return 0;
}