#include <iostream>
#include <queue>
using namespace std;

// Definition of the Node class
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Function to print the tree in level order
void printLevelOrder(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

void KthLevelOfTree(Node* root,int k) {
    if(root == NULL) return;
    if(k == 1) {
        cout << root->data << " ";
        return;
    }
    KthLevelOfTree(root->left,k-1);
    KthLevelOfTree(root->right,k-1);
}

int main() {
    // Creating a sample tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Printing the tree in level order
    // cout << "Level Order Traversal: ";
    // printLevelOrder(root);

    cout<<"Kth Level of Tree: ";
    int k = 2; // Change this value to test different levels
    KthLevelOfTree(root, k);
    cout << endl;

    return 0;
}