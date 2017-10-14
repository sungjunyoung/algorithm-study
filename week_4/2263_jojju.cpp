#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;
map<int, int> map1;

void recursive(int pivot, int left, int right, int postorderIndex) {
    printf("%d ", pivot);
    if(left == right)   return ;
    int mid = map1[pivot];
    int pivotIndex;
    if(mid != left) {
        pivotIndex = postorderIndex + mid - left - 1;
        recursive(postorder[pivotIndex], left, mid - 1, postorderIndex);
    }
    if(mid != right) {
        pivotIndex = postorderIndex - left + right - 1;
        recursive(postorder[pivotIndex], mid + 1, right, postorderIndex + mid - left);
    }
}

int main() {
    cin >> n;
    int temp = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        inorder.push_back(temp);
        map1[temp] = i;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &temp);
        postorder.push_back(temp);
    }
    recursive(postorder[n - 1], 0, n - 1, 0);
    return 0;
}