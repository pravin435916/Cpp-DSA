//  Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
class Solution {
public:
    // ListNode* mergeNodes(ListNode* head) {
    //     ListNode* fake = new ListNode(-1);
    //     ListNode* cur = fake;  //new linked list (here store sum list)
    //     ListNode* temp = head;
    //     temp = temp->next;  //skip first 0 in question given 
    //     int sum =0;
    //     while(temp) {
    //        if(temp->val == 0) {
    //          cur->next = new ListNode(sum);
    //          cur = cur->next;
    //          sum =0;   //if 0 then sum make 0 
    //        } 
    //        sum+=temp->val;
    //        temp = temp->next;
    //     }
    //     return fake->next; //pointing to current head
    //  }
    ListNode* mergeNodes(ListNode* head) {
        head = head->next;
        ListNode* temp = head;
        int sum =0;
        if(!head) return head;
        while(temp->val != 0) {
            sum += temp->val;
            temp = temp->next;
        }
        head->val = sum;
        head->next = mergeNodes(temp);
        return head; //pointing to current head
     }
};