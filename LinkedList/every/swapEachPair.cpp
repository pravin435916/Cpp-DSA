// 24. Swap Nodes in Pairs
// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
//
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]
// Explanation: Swapping nodes 1 and 2, then swapping nodes 3 and 4
class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if(head == NULL || head->next == NULL) return head;
            ListNode* temp = head->next; // store B
            head->next = swapPairs(head->next->next); // A->next = after C
            temp->next = head; // B->next = A
            return temp; // return B
        }
        // story 
        // A -> B -> C -> D
        // lest suippise have to swap A and B and other after c will solve by recursion
        // like then codniftion like A -> next = recursion(C);
        // B->next = A
        // return B
    
    };