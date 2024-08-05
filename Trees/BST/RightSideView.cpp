#include <iostream>
#include <queue>
#include <map>
#include<vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if(root == NULL) return res;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                TreeNode* cur = q.front(); 
                q.pop();
                if(i == size-1) {
                   res.push_back(cur->val);
                }
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
                
        }
        return res;
    }
    int main() {
    // Constructing a binary tree:
    //       1
    //      / \
    //     2   3
    //      \
    //       4
    //      / \
    //     5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> result = rightSideView(root);
    for(int x : result) {
        cout<<x<<" ";
    }
    return 0;
}
