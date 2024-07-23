
class Solution
{
    //easy steps to solve
    // binary search tree inorder is a sorted form of tree so question is merge both BST
    // step 1 take two tree inorder i.e in sorted order  and push in both array
    // merge both array as simple as that
private:
    void inorder(Node *root, vector<int> &a1){
        if (!root) return;
        inorder(root->left, a1);
        a1.push_back(root->data);
        inorder(root->right, a1);
    }
public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int> a1, a2;
        vector<int> res;
        inorder(root1, a1);
        inorder(root2, a2);
        int i = 0;
        int j = 0;
        while (i < a1.size() && j < a2.size()) {
            if (a1[i] < a2[j]){
                res.push_back(a1[i]);
                i++;
            }else{
                res.push_back(a2[j]);
                j++;
            }
        }
        while (i < a1.size()) {
            res.push_back(a1[i]);
            i++;
        }
        while (j < a2.size()){
            res.push_back(a2[j]);
            j++;
        }
        return res;
    }
};
