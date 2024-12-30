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
Node* ReverseLinkedList(Node* cur,Node* prev) {
    if(cur == NULL) return prev;
        Node* next = cur->next; // Store the next node
        cur->next = prev; // Reverse the link
        return ReverseLinkedList(next,cur);
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
   insertAtEnd(head,4);
   Node* prev = NULL;
   Node* head1 = ReverseLinkedList(head,prev);
   display(head1);
    return 0;
}