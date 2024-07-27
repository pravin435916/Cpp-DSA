
int countNonLeafNodes(Node* root) {
    if(!root) return  0;
    if(root->left == NULL && root->right == NULL) return 0;
    int lh = countNonLeafNodes(root->left);
    int rh = countNonLeafNodes(root->right);
    return (1+lh+rh);
    }