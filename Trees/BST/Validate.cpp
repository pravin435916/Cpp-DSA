class Solution {
public:
    void inorderTraversal(TreeNode* node, vector<int>& inorder) {
    if (!node) return;
    inorderTraversal(node->left, inorder);
    inorder.push_back(node->val);
    inorderTraversal(node->right, inorder);
}
bool isSorted(vector<int>& inorder) {
    for (int i = 1; i < inorder.size(); ++i) {  
        if (inorder[i] <= inorder[i - 1]) {
            return false;
        }
    }
    return true;
}

bool isValidBST(TreeNode* root) {
    vector<int> inorder;
    inorderTraversal(root, inorder);  //but  space complexity 0(n) extra space of vector
    return isSorted(inorder);      //if inorder is sorted bst then valid
}
};