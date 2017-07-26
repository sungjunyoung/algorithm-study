//
// Created by 성준영 on 2017. 7. 26..
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> results;

int i;

void makeTree(vector<int> &postOrder, int postIndex,
              vector<int> &inOrder, int inStart, int inEnd) {
    if (inEnd - inStart == 0) {
        results.push_back(inOrder[inEnd]);
        return;
    }
    if (inEnd - inStart == 1) {
        if (inOrder[inEnd] == postOrder[postIndex]) {
            results.push_back(inOrder[inStart]);
            results.push_back(inOrder[inEnd]);
            return;
        } else {
            results.push_back(inOrder[inEnd]);
            results.push_back(inOrder[inStart]);
            return;
        }
    }

    int inIndex;
    for (i = inEnd; i >= inStart; i--) {
        if (inOrder[i] == postOrder[postIndex]) {
            inIndex = i;
            break;
        }
    }

    if (inIndex == inEnd) {
        makeTree(postOrder, postIndex - (inEnd - inIndex) - 1,
                 inOrder, inStart, inIndex - 1); //왼쪽

    } else if (inIndex == inStart) {
        makeTree(postOrder, postIndex - 1,
                 inOrder, inIndex + 1, inEnd); //오른쪽

    } else {

        makeTree(postOrder, postIndex - 1,
                 inOrder, inIndex + 1, inEnd); //오른쪽
        makeTree(postOrder, postIndex - (inEnd - inIndex) - 1,
                 inOrder, inStart, inIndex - 1); //왼쪽
    }


    results.push_back(postOrder[postIndex]);
}

int main() {
    int n;
    cin >> n;

    vector<int> inOrder(n + 1);
    vector<int> postOrder(n + 1);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &inOrder[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &postOrder[i]);
    }


    makeTree(postOrder, (int) (postOrder.size() - 1), inOrder, 1, (int) (inOrder.size() - 1));

    for (int i = results.size() - 1; i >= 0; i--) {
        if (i == 0) {
            printf("%d", results[i]);
        } else {
            printf("%d ", results[i]);
        }
    }
}