
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        int len=0;
        while(temp != NULL) {
            len++;
            temp = temp->next;
        }
        ListNode* cur = head;
        int k = len - n;
        if(k == 0) {      //its edge case for 1st node .
            temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        while(k--) {
           prev = cur;
           cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
        return head;
    }
};