
class Solution {
  public:
   Node* pred(Node* root) {
       root = root->left;
       while(root->right){
           root = root->right;
       }
       return root;
   }
   Node* succ(Node* root) {
       root = root->right;
       while(root->left){
           root = root->left;
       }
       return root;
   }
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* cur = root;
        Node* P = nullptr;
        Node* S = nullptr;
    while(cur != nullptr) {
        if(cur->data == key){
            if(cur->left != nullptr) P =  pred(cur);
            if(cur->right != nullptr) S = succ(cur);
            break; // imp
        }else if(cur->data > key){
            S = cur;
            cur = cur->left;
        }else{
            P = cur;
            cur = cur->right;
        }
    }
        vector<Node*> ans;
        ans.push_back(P);
        ans.push_back(S);
        return ans;
    }
};