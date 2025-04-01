// 25. Reverse Nodes in k-Group
//    // Given a linked list, reverse the nodes of a linked list k at a time and return the modified list.
//    // k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//    // You may not alter the values in the nodes, only nodes themselves may be changed.
//    // Only constant memory is allowed.
//    // You may assume that all nodes in the list are 1-indexed.
//    // Input: head = [1,2,3,4,5], k = 2
//    // Output: [2,1,4,3,5]
class Solution {
    public:
      ListNode* reverse(ListNode* head, int k) {  // reverse for first k group
            ListNode *prev = nullptr, *next = nullptr, *cur = head;
            int count = 0;
            while (cur != nullptr && count < k) {
                next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
                count++;
            }
            return prev;
        }
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (head == nullptr || k <= 1) return head;
            ListNode* groupHead = nullptr;
            ListNode* newHead = nullptr;
            
            // move to k next
            ListNode* temp = head;
            int count = 0;
            while(temp && count < k) {
                temp = temp->next;
                count++;
            }
            if (count < k) return head;
            
            groupHead = reverse(head,k); // reverse first k group
            
            if(newHead == nullptr) {  // for first iteration
                newHead = groupHead; 
            }
            
            head->next = reverseKGroup(temp,k);   // recursion for next group 
            
            return newHead;
        }
    };