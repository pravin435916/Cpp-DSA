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
    //after traversing to the last . put next element ot the new node
    temp->next = new_node;
}
void insertNodeAtPosition(Node* &head, int value, int position) {
    Node* newNode = new Node(value);
    
    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Invalid position..\n";
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}
void updateAtKPos(Node* &head, int val, int k) {
    Node* newNode = new Node(val);
    Node* temp = head;
    int cur = 0;
    while(cur != k) {
        temp = temp->next;
        cur++;
    }
    temp->val = val;
}
void deleteAtHead(Node* &head) {
    Node* temp = head;
    head = head->next;
    free(temp);
}
void deleteAtEnd(Node* &head) {
    Node* second_last = head;
    while(second_last->next->next != NULL) {
        second_last = second_last->next;
    }
    Node* temp = second_last->next;
    second_last->next = NULL;
    free(temp);

}
void deleteAtPos(Node* &head, int pos) {
    Node* prev = head;
    int cur = 0;
    while(cur != pos-1) {
        prev = prev->next;
        cur++;
    }
    Node* temp = prev->next;
    prev->next = prev->next->next;
    free(temp);
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
   insertAtHead(head,2);
   insertAtHead(head,3);
   cout<<"Insert at Head : ";
   display(head);
   insertAtEnd(head,5);
   insertAtEnd(head,6);
   cout<<"Insert at End  : ";
   display(head);
   insertNodeAtPosition(head,10,2);
   cout<<"Insert at Pos : ";
   display(head);
   updateAtKPos(head,12,2);
   cout<<"Update at Pos : ";
   display(head);
   deleteAtHead(head);
   cout<<"Delete at Head : ";
   display(head);
   deleteAtEnd(head);
   cout<<"Delete at End : ";
   display(head);
   deleteAtPos(head,2);
   cout<<"Delete at Position : ";
   display(head);
    return 0;
}