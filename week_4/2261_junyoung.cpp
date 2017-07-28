//
// Created by 성준영 on 2017. 7. 28..
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

struct Dot {
    int x;
    int y;

    bool operator<(const Dot &nextDot) const {
        if (y != nextDot.y) return y < nextDot.y;
        return x < nextDot.x;
    }
};

bool operX(Dot a, Dot b) {
    return a.x < b.x;
}

int dist(Dot a, Dot b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

long long DC(vector<Dot> &dots, int start, int end) {
    if (end - start == 1) {
        return dist(dots[start], dots[end]);
    }

    int midLine = (dots[start].x + dots[end].x) / 2;

    int midIndex = (start + end) / 2;
    int leftIndex = midIndex;
    int rightIndex = leftIndex + 1;

    long long leftMin;
    long long rightMin;

    leftMin = DC(dots, start, leftIndex);

    if (rightIndex == end) {
        rightMin = dist(dots[leftIndex], dots[end]);
    } else {
        rightMin = DC(dots, rightIndex, end);
    }


    long long leftRightMin = min(leftMin, rightMin);

    set<Dot> partDots;
    while (pow(midLine - dots[leftIndex].x, 2) < leftRightMin) {
        if (leftIndex < start) {
            break;
        }
        partDots.insert(dots[leftIndex]);
        leftIndex--;
    }


    while (pow(dots[rightIndex].x - midLine, 2) < leftRightMin) {
        if (rightIndex > end) {
            break;
        }
        partDots.insert(dots[rightIndex]);
        rightIndex++;
    }

    set<Dot>::iterator iIt = partDots.begin();
    for (int i = 0; i < partDots.size(); ++i) {
        set<Dot>::iterator jIt = ++iIt;
        iIt--;

        for (int j = i + 1; j < partDots.size(); ++j) {
            if (pow((*jIt).y - (*iIt).y, 2) < leftRightMin) {
                if (leftRightMin > dist((*jIt), (*iIt))) {
                    leftRightMin = dist((*jIt), (*iIt));
                }
            } else {
                break;
            }
            jIt++;
        }
        iIt++;
    }
    return leftRightMin;
}

int main() {
    int n;
    cin >> n;

    vector<Dot> dots;
    for (int i = 1; i <= n; i++) {
        Dot dot;
        scanf("%d %d", &dot.x, &dot.y);
        dots.push_back(dot);
    }

    sort(dots.begin(), dots.end(), operX);

    printf("%lld", DC(dots, 0, (int) (dots.size() - 1)));
}