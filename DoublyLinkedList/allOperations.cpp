 #include <iostream>
using namespace std;
class Node{
   public:
   int val;
   Node* next;
   Node* prev;
   Node(int data) {
     val = data;
     next = NULL;
     prev = NULL;
   }
};
void insertAtHead(Node* &head, int val) { // O(1)
    Node* new_node = new Node(val);
    if (head == NULL) {
        head = new_node;
    } else {
        new_node->next = head;  // link next of new node to head
        head->prev = new_node;  // link prev of head to new node
        head = new_node;  // head point to new Node
    }
}
void insertAtEnd(Node* &head , int val) {
    Node* new_node = new Node(val);
    if(head == NULL) {
        insertAtHead(head,val);
    }else{
    Node* temp = head;
    while(temp->next!=NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->prev = temp;
    }
     
}
void insertAtK(Node* &head,int val,int pos) {
    Node* new_node = new Node(val);
    int count = 1;
    Node* temp = head;
    while(count < pos-1 && temp!= NULL) {
        temp = temp->next;
        count++;
    }
    new_node->next = temp->next;
    new_node->prev = temp;
    if(temp->next) {
        temp->next->prev = new_node;
    }
    temp->next = new_node;
}
void deleteFromHead(Node* &head) {
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete temp;
}
void deleteFromEnd(Node* &head) {
    Node* temp = head;
    while(temp->next) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete temp;
}
void deleteFromKPos(Node* &head,int pos) {
    int count = 1;
    Node* temp = head;
      if (pos == 1) {
        deleteFromHead(head);
        return;
    }
    while(temp!=NULL && count < pos-1) {
        temp = temp->next;
        count++;
    }
    Node* delteNode = temp->next;   // deletnnode me dal dijiye temp ka next aur temp ke next me dalo new node ka next aur new node ke next ke prev me dalo temp
    temp->next = delteNode->next;
    delteNode->next->prev = temp;
    delete delteNode;
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
   insertAtEnd(head,1);
   insertAtEnd(head,2);
   insertAtEnd(head,3);
   insertAtEnd(head,4);
   insertAtEnd(head,5);
   display(head);
   insertAtK(head,6,2);
   display(head);
   deleteFromHead(head);
   display(head);
   deleteFromEnd(head);
   display(head);
   deleteFromKPos(head,2);
   display(head);
    return 0;
}