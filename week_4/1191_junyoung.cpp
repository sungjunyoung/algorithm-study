//
// Created by 성준영 on 2017. 7. 26..
//

#include <iostream>

using namespace std;

class Node {
public:
    Node(char data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    Node *left;
    Node *right;
    char data;
};

class Tree {
public:
    Node *root;

    void searchAdd(Node *current, char data, char leftData, char rightData) {
        if (current == NULL) {
            return;
        }

        if (current->data == data) {
            current->left = new Node(leftData);
            current->right = new Node(rightData);
            return;
        } else {
            searchAdd(current->left, data, leftData, rightData);
            searchAdd(current->right, data, leftData, rightData);
            return;
        }
    }

    void add(char data, char leftData, char rightData) {
        if (data == 'A') {
            root = new Node(data);
            root->left = new Node(leftData);
            root->right = new Node(rightData);
        } else {
            searchAdd(root, data, leftData, rightData);
        }
    }

    void preOrder(Node *current) {
        if (current->data == '.') {
            return;
        }
        cout << current->data;
        preOrder(current->left);
        preOrder(current->right);
    }

    void inOrder(Node *current) {
        if (current->data == '.') {
            return;
        }
        inOrder(current->left);
        cout << current->data;
        inOrder(current->right);
    }

    void postOrder(Node *current) {
        if (current->data == '.') {
            return;
        }
        postOrder(current->left);
        postOrder(current->right);
        cout << current->data;
    }
};

int main() {
    int n;
    cin >> n;

    Tree tree;


    for (int i = 1; i <= n; i++) {
        char parent, left, right;
        scanf(" %c %c %c", &parent, &left, &right);
        tree.add(parent, left, right);
    }

    tree.preOrder(tree.root);
    cout << endl;
    tree.inOrder(tree.root);
    cout << endl;
    tree.postOrder(tree.root);
    cout << endl;
}