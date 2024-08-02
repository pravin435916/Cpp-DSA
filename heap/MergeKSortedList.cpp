class Compare {
public:
    bool operator()(Node* a,Node* b) {  //compare heads
        return a->data > b->data;
    }
};
class Solution {
  public:
    // Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr){
        priority_queue<Node*,vector<Node*>,Compare> minHeap;
        // Push the head of each list into the min heap
        for(Node* head : arr) {
            if(head) minHeap.push(head);
        }
        Node* dummy = new Node(0);
        Node* tail = dummy;
        while(!minHeap.empty()) {
            Node* small = minHeap.top(); //pick smallest head of linked lists
            minHeap.pop();
            tail->next = small; //0 -> 1
            tail = tail->next;
            if(small->next) { //if linked list next present then push it
                minHeap.push(small->next);
            }
        }
        return dummy->next;
    }};
