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

vector<int> bottomView(TreeNode* root) {
    if (!root) return {};

    // Map to store the bottom view
    map<int, int> mp;

    // Queue for BFS: stores pairs of (node, horizontal distance)
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int hd = front.second;

        // Update the map with the latest node at this horizontal distance
        mp[hd] = node->val;

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
    for (const auto& entry : hdMap) {
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
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(5);

    vector<int> result = bottomView(root);
    printVector(result);  // Output: 5 4 6 3

    // Cleanup: Deleting nodes to prevent memory leaks
    delete root->left->right->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
