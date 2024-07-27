#include <bits/stdc++.h>

class Solution
{
    public:
    vector<int> largestValues(Node* root)
    {
       vector<int> res;
      queue<Node*> q;
      q.push(root);
      while(!q.empty()) {
          int maxi = INT_MIN;
          int size = q.size();
          while(size--) {
          Node* node = q.front();
          q.pop();
          maxi = max(maxi,node->data); 
          if (node->left != NULL) {
            q.push(node->left);
          }

         if (node->right != NULL) {
            q.push(node->right);
          }
         }
         res.push_back(maxi);
      }
      return res;
    }
};
