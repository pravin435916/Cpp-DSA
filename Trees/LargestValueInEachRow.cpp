
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        // steps to solve
        // 1. push node to queue and push every child to queue and push max node
        // to vector
        if (root == nullptr) {
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<int> res;
        while (!q.empty()) {
            int size = q.size();
            int cur = INT_MIN;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                cur = max(cur, node->val);
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }
            res.push_back(cur);
        }
        return res;
    }
};