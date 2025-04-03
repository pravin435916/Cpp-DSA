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
      ListNode* reverseList(ListNode* head) {
            ListNode* prev = nullptr;
            ListNode* curr = head;
            while (curr) {
                ListNode* nextNode = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextNode;
            }
            return prev;
        }
        ListNode* doubleIt(ListNode* head) {
            // brute force
            // merge it and then multiply by 2 
            // then build
            head = reverseList(head);
            
            ListNode* cur = head;
            ListNode* prev = nullptr;
            int carry = 0;
    
            while (cur) {
                int newVal = cur->val * 2 + carry;
                cur->val = newVal % 10;  // Store last digit
                carry = newVal / 10;  // Carry forward the remaining value
                prev = cur;
                cur = cur->next;
            }
    
            if(carry != 0) {
                ListNode* newHead = new ListNode(carry);
                prev->next = newHead;
            }
    
            return reverseList(head);
        }
    };