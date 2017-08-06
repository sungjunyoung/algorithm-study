#include <iostream>
#include <algorithm>
using namespace std;
struct node {
    node* parent;
    node* left;
    node* right;
    int idx;
    int in_pos;
    int post_pos;
};
node* root = new node;

int n;
int inorder[100001];
bool chk_inorder[100001];
int postorder[100001];
bool chk_postorder[100001];
void findpos(node* node) {
    for (int i = 1; i <= n; i++) {
        if (inorder[i] == node->idx) {
            node->in_pos = i;
            chk_inorder[i] = true;
            break;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (postorder[i] == node->idx) {
            node->post_pos = i;
            chk_postorder[i] = true;
            break;
        }
    }
    return;
}
void maketree(node* root_node, int l_s, int l_e,int r_s,int r_e) {
    node* left = new node;
    node* right= new node;
    left->idx = 0;
    left->in_pos = -1;
    left->post_pos = -1;
    left->left = nullptr;
    left->right = nullptr;
    left->parent = nullptr;
    right->idx = 0;
    right->in_pos = -1;
    right->post_pos = -1;
    right->left = nullptr;
    right->right = nullptr;
    right->parent = nullptr;
    //오른쪽 서브트리
    //오른쪽 서브트리 제약조건
    if (root_node->in_pos + 1 >n || chk_inorder[root_node->in_pos + 1] == true) {
        ;
    }
        //제약조건을 피하면
    else {
        root_node->right = right;
        right->parent = root_node;
        right->idx = postorder[root_node->post_pos-1];
        findpos(right);
        right->left = nullptr;
        right->right = nullptr;
        maketree(right, r_s, right->in_pos - 1, right->in_pos + 1, r_e);
    }
    //왼쪽 서브트리
    //왼쪽 서브트리 제약조건
    if (root_node->in_pos - 1 < 1 || chk_inorder[root_node->in_pos - 1] == true) {
        ;
    }
        //제약조건을 피하면
    else {
        root_node->left = left;
        left->parent = root_node;
        left->idx = postorder[root_node->post_pos-(r_e-root_node->in_pos + 1)];
        findpos(left);
        left->left = nullptr;
        left->right = nullptr;
        maketree(left, l_s, left->in_pos-1, left->in_pos + 1, l_e);
    }
}

void print(node* A) {
    cout << A->idx << " ";
    if (A->left != nullptr)
        print(A->left);
    if (A->right != nullptr)
        print(A->right);
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> inorder[i];
    for (int i = 1; i <= n; i++)
        cin >> postorder[i];

    root->idx = 0;
    root->in_pos = -1;
    root->post_pos = -1;
    root->left = nullptr;
    root->right = nullptr;
    root->parent = nullptr;
    root->idx = postorder[n];
    findpos(root);
    maketree(root, 1, root->in_pos - 1, root->in_pos + 1, n);
    print(root);
    return 0;
}