#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
//leaf nodes print
void leftNode(Node* root,vector<int> &ans) { 
    if (root == NULL || ( root->left == NULL && root->right == NULL)) return;

    if(root->left) {
         leftNode(root->left,ans);
    }else{
        leftNode(root->right,ans);
    }
    ans.push_back(root->data);
}
//right nodes print
void rightNode(Node* root,vector<int> &ans) { 
    if (root == NULL || ( root->left == NULL && root->right == NULL)) return;
    //already leaf nodes function pinted ndes so you have to avoid leaf node here
    if(root->right) {
         rightNode(root->right,ans);
    }else{
        rightNode(root->left,ans);
    }
    ans.push_back(root->data);
}

void leafNode(Node* root,vector<int> &ans) { 
    
    if (root == NULL ) return;
    if(root->left == NULL && root->right == NULL) {
    //  cout << root->data << " ";
    ans.push_back(root->data);
    }
    
    leafNode(root->left,ans);
    leafNode(root->right,ans);
}
void display(vector<int> ans) {
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}
//     1
// 2      3
//5 6    7 8
int main() {
    Node* root = new Node(1);                           
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    vector<int> ans;
    if(root == NULL) return {};
    ans.push_back(root->data);  //print root data
    leftNode(root->left,ans);   //print only leftv node  without root and leaf node
    leafNode(root,ans);  //print only leaf node
    rightNode(root->right,ans); //print only right node  without root and leaf node
    display(ans);
    return 0;
}
