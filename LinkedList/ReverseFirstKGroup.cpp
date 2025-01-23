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
Node* ReverseLinkedList(Node* head, int k) {
    Node* first = new Node(-1);
    first->next = head;
    head = first;
    Node* front;
    while(first->next) {
        int x = k;
        Node* sec = first->next;
        Node* prev = first;
        Node* cur = first->next;
        while(x-- && cur) {
        front = cur->next;
        cur->next = prev;
        prev = cur;
        cur = front;
        }
     
    first->next = prev;
    sec->next = cur;
    first = sec;
    }
    first = head;
    head = head->next;

    return head;
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
   insertAtEnd(head,5);
   insertAtEnd(head,6);
   Node* prev = NULL;
   Node* head1 = ReverseLinkedList(head,3);
   display(head1);
    return 0;
}