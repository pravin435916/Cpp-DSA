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
        ListNode* insertGreatestCommonDivisors(ListNode* head) {
           ListNode* cur = head;
    
           while(cur->next) {
              int gcd = __gcd(cur->val,cur->next->val);
              ListNode* newNode = new ListNode(gcd);
              newNode->next = cur->next;
              cur->next = newNode;  // cur next point to the gcd node
              cur = cur->next->next;
           }
           return head;
        }
    };