class Solution {
public:
    void mapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parentMap) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        parentMap[root] = NULL;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parentMap[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
    }
    TreeNode* findTarget(TreeNode* root, int start) {
        if (!root) return NULL;
        if (root->val == start) return root;
        TreeNode* leftSearch = findTarget(root->left, start);
        if (leftSearch) return leftSearch;
        return findTarget(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start) {
        if (!root) return 0;

        unordered_map<TreeNode*, TreeNode*> parentMap;
        mapParents(root, parentMap);

        TreeNode* targetNode = findTarget(root, start);
        if (!targetNode) return 0;  // If target is not found, return 0.

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        int time = 0;

        // Traverse to nodes
        while (!q.empty()) {
            int size = q.size();
            bool anyNodeBurnt = false;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Burn left child
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                    anyNodeBurnt = true;
                }

                // Burn right child
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                    anyNodeBurnt = true;
                }

                // Burn parent
                if (parentMap[node] && !visited[parentMap[node]]) {
                    q.push(parentMap[node]);
                    visited[parentMap[node]] = true;
                    anyNodeBurnt = true;
                }
            }

            if (anyNodeBurnt) {
                time++;
            }
        }

        return time;
    }
};