class Solution {
public:
//find position in inorder so we can partition it
int findNode(vector<int>& in,int key,int start,int end) {
    for(int i=start;i<=end;i++) {
        if(in[i] == key) return i;
    }
    return -1;
}
TreeNode* BuildTree(vector<int>& pre, vector<int>& in,int start,int end,int &idx) {
        if(start > end) return NULL; //edge case
        TreeNode* root = new TreeNode(pre[idx]);  //make new Node
        int pos = findNode(in,pre[idx],start,end); //find
        idx++; //increment to new index
        root->left = BuildTree(pre,in,start,pos-1,idx);  
        root->right = BuildTree(pre,in,pos+1,end,idx);
        return root;
    }
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n = pre.size();
        int idx = 0;
        return BuildTree(pre,in,0,n-1,idx);
    }
};