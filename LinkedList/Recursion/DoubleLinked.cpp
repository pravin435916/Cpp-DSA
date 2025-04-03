
class Solution {
    public:
      int doubleUtil(ListNode* head) {
        if(head == nullptr) return 0;
        int carry = doubleUtil(head->next);
        int newVal = head->val * 2 + carry;
        head->val = newVal % 10; 
        return newVal/10; //return carry
        }
        ListNode* doubleIt(ListNode* head) {
            int lastcarry = doubleUtil(head);
            if(lastcarry > 0) { // if carry
                ListNode* newHead = new ListNode(lastcarry);
                newHead->next = head;
                return newHead;
            }
    
            return head;
            
        }
    };