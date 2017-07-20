#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

struct point{
    int x;
    int y;
    bool operator < (const point& nextPoint) const
    {
        if(y != nextPoint.y) return y < nextPoint.y;
        return x < nextPoint.x;
    }
};

bool compareByX(const point &first, const point &second)
{
    if(first.x != second.x) return first.x < second.x;
    return first.y < second.y;
}

int getMin(int a, int b)
{
    if(a<b) return a;
    return b;
}

int getDistace(point point1, point point2) {
    return (int) (pow(point1.x - point2.x , 2) + pow(point1.y - point2.y , 2));
}

int getMinDistance(vector<point> & pointArray, int start, int end) {

    if(end - start == 1)    return   getDistace(pointArray[start],pointArray[end]);

    int left = (end+start) / 2;
    int right = left + 1;

    int rightSideMin;
    if(right == end)
        rightSideMin =  getDistace(pointArray[left],pointArray[end]);
    else
        rightSideMin = getMinDistance(pointArray, right, end);

    int leftSideMin = getMinDistance(pointArray, start, left);

    int curMinDistance = getMin(leftSideMin, rightSideMin);

    int middleLine = (pointArray[left].x + pointArray[right].x) / 2;

    set<point> middleArray;
    while(start <= left && middleLine - sqrt(curMinDistance) - 1 < pointArray[left].x)
    {
        middleArray.insert(pointArray[left]);
        left--;
    }

    while(right <= end && pointArray[right].x < middleLine + sqrt(curMinDistance) + 1)
    {
        middleArray.insert(pointArray[right]);
        right++;
    }

    set<point>::iterator IterPos = middleArray.begin();
    for (int i = 0; i < middleArray.size(); ++i) {
        set<point>::iterator subIterPos = ++IterPos;
        IterPos--;
        for (int j = i + 1; j < middleArray.size(); ++j) {
            if((*subIterPos).y - (*IterPos).y < sqrt(curMinDistance) + 1)
            {
                if(getDistace((*subIterPos),(*IterPos)) < curMinDistance)
                    curMinDistance = getDistace((*subIterPos),(*IterPos));
            }
            else
                break;
            subIterPos++;
        }
        IterPos++;
    }

    return curMinDistance;
}
int main()
{
    int totalPoint;
    cin>>totalPoint;

    vector <point> pointArray;
    point input;
    for (int curPoint = 0; curPoint < totalPoint; ++curPoint) {
        cin>>input.x;
        cin>>input.y;
        pointArray.push_back(input);
    }
    sort(pointArray.begin(), pointArray.end(), compareByX);

    cout<<getMinDistance(pointArray,0,totalPoint - 1)<<endl;

    return 0;
}