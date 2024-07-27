int countLeaves(Node* root)
{
    if(!root) return 0;
    if(root->left == NULL && root->right == NULL) return 1;
    int lh = countLeaves(root->left);
    int rh = countLeaves(root->right);
    return lh+rh;
}