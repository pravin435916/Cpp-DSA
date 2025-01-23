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
Node* reverseksteps(Node* &head,int k) {
    int n = 0;
    Node* tail = head;
    while(tail->next) {   
        n++;    //find length
        tail = tail->next;   // poin to last
    }
    k=k%n;
    if(k==0) {
        return head;
    }
    tail->next = head;   //last point to head
    Node* temp = head;
    for(int i=0;i<n-k;i++) {
        temp = temp->next;  // from first node to n-k
    }
    Node* newhead = temp->next;  // new head temp ka next hoga
    temp->next = NULL;  // null point krde
    return newhead;   //new head     
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
   Node* newHead = reverseksteps(head,2);
   display(newHead);
    return 0;
}