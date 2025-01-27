// used heap sort instead of merge sort for its hard implementation
// Both takes o(nlogn) time   and o(n) space 

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // Step 1: Insert all elements of the linked list into the heap
        ListNode* current = head;
        while (current) {
            minHeap.push(current->val);
            current = current->next;
        }
        // Step 2: Pop elements from the heap and rebuild the linked list
        ListNode* newHead = nullptr;
        ListNode* tail = nullptr;

        while (!minHeap.empty()) {
            int value = minHeap.top();
            minHeap.pop();

            // Create new node with the popped value
            ListNode* newNode = new ListNode(value);

            // If this is the first node, set it as head
            if (!newHead) {
                newHead = newNode;
                tail = newHead;
            } else {
                tail->next = newNode;
                tail = tail->next;
            }
        }

        return newHead;
    }
};