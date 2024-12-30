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
void insertAtHead(Node* &head,int val) { //o(1)
    Node* new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}
void insertAtEnd(Node* &head,int val) {  //o(n)
    Node* new_node = new Node(val);
    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}
void minmax(Node* &head) {
    Node* prev = NULL;
    Node* cur = head;
    int count = 0;
    while(cur != NULL) {
        if(prev == NULL || cur->val < prev->val && cur->val < cur->next->val) {
           count++;
        }
        //  if( cur->val > prev->val && cur->val > cur->next->val) {
        //    count++;
        // }
        prev = cur;
        cur = cur->next;
    }
    cout<<"count : "<<count<<endl;
}

void display(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
int main()
{
   Node* head = NULL;
   insertAtHead(head,1);
   insertAtEnd(head,2);
   insertAtEnd(head,3);
   insertAtEnd(head,3);
   insertAtEnd(head,3);
   insertAtEnd(head,5);
   insertAtEnd(head,1);
   insertAtEnd(head,3);
   display(head);
   minmax(head);
   display(head);
    return 0;
}