#include <iostream>
using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

bool checkBalance(TreeNode* node) {
    int leftH = 0;
    int rightH = 0;
    TreeNode* temp = node;

    while (temp && temp->left) {
        leftH++;
        temp = temp->left;
    }

    temp = node;

    while (temp && temp->right) {
        rightH++;
        temp = temp->right;
    }
    //chec both height equal
    if(leftH != rightH) {
        return false;
    }else{
        return true;
    }
    cout << "Left height : " << leftH << endl;
    cout << "Right height : " << rightH << endl;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->left->left = new TreeNode(6);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(7);
    // root->left->right->left->left = new TreeNode(8);

    if(checkBalance(root)) {
        cout << "1"<<endl;
    }else{
        cout << "0"<<endl;
    }

    return 0;
}
