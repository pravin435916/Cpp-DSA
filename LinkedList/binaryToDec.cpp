 #include <iostream>
  #include <cmath>
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
// int getDecimal(Node* &head) {
//     Node* temp = head;
//     int sum = 0;
//     int power = 0;
//     while(temp!=NULL){
//         sum = temp->val + pow(2,power);
//         temp = temp->next;
//         power++;
//     }
//     return sum;
// }
 int getDecimal(Node* head) {
        int sum = 0;
        while (head != nullptr) { 
            sum = (sum << 1) + head->val; //another approach left shift 
            head = head->next;
        }
        return sum;
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
   insertAtEnd(head,0);
   insertAtEnd(head,1);
   display(head);
   int dec = getDecimal(head);
   cout<<"dec : "<<dec<<endl;
   cout << (2 >> 1) <<endl;
    return 0;
}