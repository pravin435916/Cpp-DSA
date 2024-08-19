class Solution {
public:
    void inorder(TreeNode* root, vector<int> &ans) {
        if(root == NULL) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    // approach to solve
    // 1. find inorder bcoz we want increasing nodes
    // 2. traverse in inorder array
    // 3. make a newNode to store its root
    // 4. aand make a dummy node and push all node to its right and move right 
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        TreeNode* dummy = new TreeNode(-1);
        TreeNode* newNode = dummy;
        for(int x : ans) {
            dummy->right = new TreeNode(x);
            dummy = dummy->right;
        }
        return newNode->right;
    }
};