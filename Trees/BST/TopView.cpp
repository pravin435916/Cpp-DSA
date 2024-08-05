#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> topView(TreeNode* root) {
    if (!root) return {};

    // Map to store the top view
    map<int, int> mp;

    // Queue for BFS: stores pairs of (node, horizontal distance)
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int hd = front.second;

        // Insert the node into the map only if it's the first node at this horizontal distance
        if (mp.find(hd) == mp.end()) {
            mp[hd] = node->val;
        }

        // Enqueue left and right children with updated horizontal distances
        if (node->left) {
            q.push({node->left, hd - 1});
        }
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    // Extract the values from the map and return
    vector<int> result;
    for (const auto& entry : mp) {
        result.push_back(entry.second);
    }
    return result;
}

// Helper function to print the vector
void printVector(const vector<int>& v) {
    for (int val : v) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Constructing a binary tree:
    //       1
    //      / \
    //     2   3
    //      \
    //       4
    //      / \
    //     5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    vector<int> result = topView(root);
    printVector(result);  // Expected Output: 2 1 3 6
    return 0;
}
