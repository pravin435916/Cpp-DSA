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

void preorder(Node* root) {  // root - left - right (NLR)
    if (root == NULL) return;
    std::cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {  // left - root - right (LNR)
    if (root == NULL) return;
    inorder(root->left);
    std::cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node* root) {  // left - right - root (LRN)
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    std::cout << root->data << " ";
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    preorder(root);
    // inorder(root);
    // postorder(root);

    return 0;
}
