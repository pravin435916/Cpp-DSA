// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* fake = new ListNode(-1);
        ListNode* temp = fake;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = 0;  //after sum then 0
            if (l1) {
                sum += l1->val;  //2  4
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val; //2+5 4+6
                l2 = l2->next;
            }
            sum += carry; //2+5+0  //4+6+0
            carry = sum / 10;      //10/10 =>1                   
            ListNode* newNode = new ListNode(sum % 10); // 10%10 => 0
            temp->next = newNode;
            temp = temp->next;
        }
        return fake->next;
    }
};