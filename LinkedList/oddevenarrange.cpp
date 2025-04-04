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
void oddEvenArrangement(Node* &head) {
    if (head == NULL || head->next == NULL) {
        // No need to rearrange if the list is empty or has only one element
        return;
    }
    Node* oddhead = head;
    Node* evnhead = head->next;
    Node* evenptr = evnhead;

    while (oddhead != NULL && oddhead->next != NULL) {
        oddhead = oddhead->next->next;
    }
    if (oddhead != NULL) {
        oddhead->next = evenptr;
    }
    while (evnhead != NULL && evnhead->next != NULL) {
        evnhead = evnhead->next->next;
    }
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
   display(head);
   oddEvenArrangement(head);
   display(head);
    return 0;
}