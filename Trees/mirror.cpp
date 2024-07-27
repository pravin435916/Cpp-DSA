#include <iostream>
using namespace std;
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
int sumOfBinaryTree(Node* root,int curSum) {
    if(!root) return curSum;
    curSum+=root->data;
    curSum= sumOfBinaryTree(root->left,curSum);
    curSum= sumOfBinaryTree(root->right,curSum);
    return curSum;
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
    cout<<sumOfBinaryTree(root,0)<<endl;
    return 0;
}
