// Input: head = [1,1,2]
// Output: [1,2]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* temp = head;
        while(temp->next != nullptr) {
            if(temp->val == temp->next->val) {
                ListNode* dup = temp->next;
                temp->next = temp->next->next;
                delete dup;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
