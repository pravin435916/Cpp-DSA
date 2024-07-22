class Solution{
    private:
    vector<int> largestBST(Node* root) {
        if(!root) {
            // size true/false minval , maxval
            return {0,1,INT_MAX,INT_MIN};
        }
        vector<int> leftRes =largestBST(root->left);
        vector<int> RightRes =largestBST(root->right);
        
        if(leftRes[1] && RightRes[1] && (root->data > leftRes[3] && root->data < RightRes[2])) {  //if left and right tree true
            int size = leftRes[0] + RightRes[0] + 1;
            int minVal = min(root->data, leftRes[2]);
            int maxVal = max(root->data, RightRes[3]);
            return {size, 1, minVal, maxVal};
        }
          // Current subtree is not a BST
        int size = max(leftRes[0], RightRes[0]);
        return {size, 0, 0, 0};
    }
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	 return largestBST(root)[0];
    }
};