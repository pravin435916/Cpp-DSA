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

void deleteAlternate(Node* &head) {
    Node* cur = head;
    while(cur != NULL && cur->next != NULL) {
        Node* temp = cur->next;
        // cur->next  = temp->next; //first way
        cur->next  = cur->next->next; //second way
        free(temp);
        cur = cur->next;
    }

}
 Node* removeDuplicates(Node* &head) {
        Node* cur = head;
        while(cur != NULL && cur->next != NULL) {
            if(cur->val == cur->next->val) {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                free(temp);
            }
            cur = cur->next;
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
   insertAtEnd(head,2);
   insertAtEnd(head,4);
   insertAtEnd(head,6);
   insertAtEnd(head,6);
   display(head);
   removeDuplicates(head);
   display(head);
    return 0;
}