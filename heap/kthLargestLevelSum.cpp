/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1; // If the tree is empty, return -1

        queue<TreeNode*> q;
        q.push(root);

        priority_queue<long long,vector<long long>,greater<long long>> minHeap;

        while (!q.empty()) {
            int levelSize = q.size();
            long long levelSum = 0;

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();

                levelSum += node->val;

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }

            minHeap.push(levelSum);

            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // The root of the heap is the k-th largest level sum
        return (minHeap.size() == k) ? minHeap.top() : -1;
    }
};