// Problem: Remove every kth node from the linked list
// Given a linked list, remove every kth node from the linked list.
// Input: head = [1,2,3,4,5], k = 2
// Output: [1,3,4,5]
class Solution {
    public:
      Node* solveDelete(Node* head,int k ,int count) {
          if(!head) return nullptr;
          if(count % k == 0) { // every kth node then skip it
              return  solveDelete(head->next,k,count+1);
          }
          head->next  = solveDelete(head->next,k,count+1);
          return head;
      }
      Node* deleteK(Node* head, int k) {
         if(!head) return nullptr;
         return solveDelete(head,k,1);
      }
  };