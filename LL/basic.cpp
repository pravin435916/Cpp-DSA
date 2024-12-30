#include <iostream>
using namespace std;
class Node{
   public:
   int val;
   Node* next;
   Node(int data) {
     val = data;
     next = NULL;
   }
};
int main()
{
    Node* node = new Node(1);
    cout<<node->val<<"->"<<node->next;
    return 0;
}