 int getSize(Node* root) {
    if(!root) return 0;
    int lh = getSize(root->left);
    int rh = getSize(root->right);
    return 1+lh+rh;
    }