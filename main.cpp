#include <bits/stdc++.h>
using namespace std;

// node for binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// inorder tree traversal iteratively
void inorder(struct Node *root) {
    stack<Node *> s;
    Node *current = root;

    while (current != NULL || !s.empty()) {
        // reach the left most node
        while (current != NULL) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        cout << current->data << " ";

        current = current->right;
    }
}

int main() {
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inorder(root);

    return 0;
}
