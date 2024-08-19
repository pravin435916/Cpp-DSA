class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return  new TreeNode(val);
        if(val < root->val) {
            root->left = insertIntoBST(root->left,val);
        }else{
            root->right = insertIntoBST(root->right,val);
        }
        return root;
    }
};