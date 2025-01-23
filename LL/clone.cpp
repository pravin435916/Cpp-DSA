class Solution {
  public:
    Node *cloneLinkedList(Node *head) {
         if(!head) return nullptr;
         // hashmap for original -> copied
         
         unordered_map<Node*,Node*> mp;
         // step 1 : push all copied nodes in hasmap
         Node* temp = head;
         while(temp != nullptr) {
             Node* newNode = new Node(temp->data);
             mp[temp] = newNode;  // stored its copied node
             temp = temp->next;
         }
         
         // step 2 : connect all with next and random pointer
         temp = head;
         while(temp != nullptr) {
             Node* copyNode = mp[temp];    //its copy node from hashmap
             copyNode->next = mp[temp->next];  // next pointer of copyNode is next of original node
             copyNode->random = mp[temp->random]; // random pointer of copyNode is random of original node
             temp = temp->next;
         }
         return mp[head]; // return head of copied linked list
    }
};