class Solution {
public:
    void helper(TreeNode* root, int low, int high,int &sum) {
        if(root == NULL) return;
        if(root->val >= low && root->val <= high) {
            sum+=root->val;  // if in range add node value in sum
        }
        helper(root->left,low,high,sum);
        helper(root->right,low,high,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum = 0;
        helper(root,low,high,sum);
        return sum;
    }
};