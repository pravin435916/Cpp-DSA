// Q. 2487. Remove Nodes From Linked List
// You are given the head of a linked list.
// Remove every node which has a node with a greater value anywhere to the right side of it.
// Return the head of the modified linked list.
class Solution {
public:
// 1st approach
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = nullptr;
    //     ListNode* cur = head;
    //     while (cur) {
    //         ListNode* nextNode = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = nextNode;
    //     }
    //     return prev;
    // }
    
    // ListNode* removeNodes(ListNode* head) {
    //     if (!head) return head;
    //     // Step 1: Reverse 
    //     head = reverseList(head);

    //     // Step 2:  reversed list and remove nodes
    //     ListNode* dummy = new ListNode(-1);
    //     dummy->next = head;
    //     ListNode* cur = head;
    //     ListNode* prev = dummy;
    //     while (cur && cur->next) {
    //         if (cur->val > cur->next->val) { // 8 3 13
    //             ListNode* temp = cur->next; //3
    //             cur->next = cur->next->next;//8_>13
    //             delete temp; //3
    //         } else {
    //             cur = cur->next;
    //         }
    //     }

    //     // Step 3: Reverse 
    //     head = reverseList(dummy->next);
    //     delete dummy;
    //     return head;
    // }
    //using stack
     ListNode* removeNodes(ListNode* head) {
        stack<ListNode* > st;
        ListNode* cur = head;
        while(cur) {
            st.push(cur);
            cur = cur->next;
        }
        cur = st.top();
        st.pop();
        int maxi = cur->val;
        ListNode* newList = new ListNode(maxi); //8 ->
        while(!st.empty()) {
             cur = st.top();
             st.pop();
             if(cur->val < maxi) continue;
             else {
                ListNode* newNode = new ListNode(cur->val);
                newNode->next = newList;
                newList = newNode;
                maxi = cur->val;
             }
        }
             return newList;
    }
};
