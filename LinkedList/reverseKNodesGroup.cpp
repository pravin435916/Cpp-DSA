/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
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
        
        groupHead = reverse(head,k);
        
        if(newHead == NULL) {  // this case for first reverse k nodes
            newHead = groupHead;
        }
        
        head->next = reverseKGroup(temp,k);
        
        return newHead;
    }
};