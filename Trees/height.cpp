#include <iostream>
#include <algorithm>
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

int height(Node* root) {
    if (root == NULL) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);  // Height of the current node is 1 plus the maximum height of its subtrees
}
int diameter(Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);  
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    int ans = leftHeight+rightHeight+1;

    return max(ans , max(ld, rd));  // Height of the current node is 1 plus the maximum height of its subtrees
}
// int diameterOfBinaryTree(Node* root) {
//   int diameter=0;
//   int h = height(root,diameter);
//   return diameter;
// }
//     int height(Node* root,int &diameter) {
//         if(root == NULL) return -1;
//         int lh = height(root->left,diameter);
//         int rh = height(root->right,diameter);
//         diameter =  max(diameter,2+lh+rh);
//         return 1+max(lh,rh);
//     }

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->right->right = new Node(8);
    int ht = height(root);
    std::cout<<ht<<endl;
    cout<<diameterOfBinaryTree(root);
    // inorder(root);
    // postorder(root);

    return 0;
}
