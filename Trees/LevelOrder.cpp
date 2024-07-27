
class Solution
{
    public:
    vector<int> levelOrder(Node* root)
    {
      vector<int> res;
      queue<Node*> q;
      q.push(root);
      while(!q.empty()) {
          Node* node = q.front();
          q.pop();
          res.push_back(node->data);
          if (node->left != NULL) {
            q.push(node->left);
        }

        if (node->right != NULL) {
            q.push(node->right);
        }

      }
      return res;
    }
};