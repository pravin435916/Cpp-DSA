// Input: root = [1,2,3]
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.

// Input: root = [4,9,0,5,1]
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.
class Solution {
public:
    int SumofTree(Node* root,int cur) {
        if(root == nullptr) return 0;
        cur = cur * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr) return cur;
        int lsum = SumofTree(root->left,cur);
        int rsum = SumofTree(root->right,cur);
        return lsum+rsum;
    }
    int sumNumbers(Node* root) {
        return SumofTree(root,0);
    }
};