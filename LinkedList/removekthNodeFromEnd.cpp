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

void removekthNodefromEnd(Node* &head,int k) {  // shabbash beta
     Node* ptr1 = head;
     Node* ptr2 = head;
     int count = k;
     while(count--) {
        ptr2 = ptr2->next;
     }
     while (ptr2->next != NULL)
     {
        ptr2 = ptr2->next;
        ptr1 = ptr1->next;
     }
     if(ptr1 == NULL) {
        Node* tmp = head;
        head = head->next;
        free(tmp);
     }
     Node* temp = ptr1->next;
     ptr1->next = ptr1->next->next;
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
   insertAtEnd(head,2);
   insertAtEnd(head,3);
   insertAtEnd(head,4);
   insertAtEnd(head,5);
   display(head);
   removekthNodefromEnd(head,2);
   display(head);
    return 0;
}