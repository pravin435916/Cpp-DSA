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

void leafNode(Node* root,int &sum) { 
    
    if (root == NULL ) return;
    if(root->left == NULL && root->right == NULL) {
       sum+=root->data;
    }
    
    leafNode(root->left,sum);
    leafNode(root->right,sum);
}
void rightNode(Node* root,int &sum) { 
    if (root == NULL) return;
    //already leaf nodes function pinted ndes so you have to avoid leaf node here
    if(root->right) {
         rightNode(root->right,sum);
    }else{
        rightNode(root->left,sum);
    }
    sum+=root->data;
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
    int sum =0;
    // leafNode(root,sum);  //print only leaf node
    // cout<<sum<<endl;
    rightNode(root,sum);  //print only leaf node
    cout<<sum<<endl;
    // display(ans);
    return 0;
}
