#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


struct RectangleWithId {
    int index;
    int size;
};

struct SegmentTreeNode {
    int recIndex;
    int start;
    int end;
};

bool asc(RectangleWithId A, RectangleWithId B) {
    return A.size < B.size;
}

SegmentTreeNode createSegmentTree(vector<int> &rectangles, vector<RectangleWithId> &rectanglesWithId, int segmentStart,
                                  int segmentEnd, vector<SegmentTreeNode> &segmentTree, int curIndex) {
    if (segmentStart == segmentEnd) {
        SegmentTreeNode stn;
        stn.recIndex = segmentStart;
        stn.start = segmentStart;
        stn.end = segmentEnd;
        segmentTree[curIndex] = stn;
        return stn;
    }

    int mid = (segmentStart + segmentEnd) / 2;


    SegmentTreeNode first = createSegmentTree(rectangles, rectanglesWithId, segmentStart, mid, segmentTree,
                                              curIndex * 2 + 1);
    SegmentTreeNode second = createSegmentTree(rectangles, rectanglesWithId, mid + 1, segmentEnd, segmentTree,
                                               curIndex * 2 + 2);

    if (rectangles[first.recIndex] > rectangles[second.recIndex]) { first = second; }
    first.start = segmentStart;
    first.end = segmentEnd;

    segmentTree[curIndex] = first;

    return segmentTree[curIndex];
}

int query(vector<int> &rectangles, vector<SegmentTreeNode> &segmentTree, int nodeIndex, int queryStart, int queryEnd) {
    if (queryStart <= segmentTree[nodeIndex].start && queryEnd >= segmentTree[nodeIndex].end) {
        // 노드의 범위 안에 있을때
        return segmentTree[nodeIndex].recIndex;
    } else if (segmentTree[nodeIndex].end < queryStart || segmentTree[nodeIndex].start > queryEnd) {
        // 노드 범위 내에 하나도 없을때
        return -1;
    } else {
        int first = query(rectangles, segmentTree, nodeIndex * 2 + 1, queryStart, queryEnd);
        int second = query(rectangles, segmentTree, nodeIndex * 2 + 2, queryStart, queryEnd);

        // -1 : INFINITE
        if (first == -1 && second == -1) {
            return -1;
        } else if (first == -1) {
            return second;
        } else if (second == -1) {
            return first;
        } else {
            if (rectangles[first] > rectangles[second]) {
                return second;
            } else {
                return first;
            }
        }
    }
}


long long largest(vector<int> &rectangles, vector<SegmentTreeNode> &segmentTree, int start, int end) {
    int m = query(rectangles, segmentTree, 0, start, end);
    long long area = (long long) (end - start + 1) * (long long) rectangles[m];
    if (start <= m - 1) {
        long long temp = largest(rectangles, segmentTree, start, m - 1);
        if (area < temp) {
            area = temp;
        }
    }
    if (m + 1 <= end) {
        long long temp = largest(rectangles, segmentTree, m + 1, end);
        if (area < temp) {
            area = temp;
        }
    }
    return area;
}


int main() {

    while (1) {
        int n;
        cin >> n;
        if (n == 0) {
            return 0;
        }
        vector<int> rectangles(n);
        vector<RectangleWithId> rectanglesWithId(n);
        int h = (int) (ceil(log2(n)) + 1e-9);
        int tree_size = (1 << (h + 1));
        vector<SegmentTreeNode> segmentTree(tree_size);
        long long max;

        for (int i = 0; i < n; i++) {
            scanf("%d", &rectangles[i]);
            RectangleWithId temp;
            temp.index = i;
            temp.size = rectangles[i];
            rectanglesWithId[i] = temp;
        }

        sort(rectanglesWithId.begin(), rectanglesWithId.end(), asc);

        createSegmentTree(rectangles, rectanglesWithId, 0, n - 1, segmentTree, 0);

        // 세그먼트 트리로 최대값 구하기
        cout << largest(rectangles, segmentTree, 0, n-1) << endl;
    }
    return 0;
}

