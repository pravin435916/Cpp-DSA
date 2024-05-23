#include <iostream>
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void mirror(Node* root) { 
    if (root == NULL) return;
    std::cout << root->data << " ";
    std::swap(root->left,root->right);
    mirror(root->left);
    mirror(root->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->right->left = new Node(3);
    root->right->right = new Node(7);
    mirror(root);

    return 0;
}
