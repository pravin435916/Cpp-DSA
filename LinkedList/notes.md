# Linked List (LL) Notes

## Introduction
- A linked list is a linear data structure where elements are stored in nodes.
- Each node contains a data part and a reference (or link) to the next node in the sequence.

## Types of Linked Lists
1. **Singly Linked List**: Each node points to the next node.
2. **Doubly Linked List**: Each node points to both the next and the previous node.
3. **Circular Linked List**: The last node points back to the first node.

## Basic Operations
- **Insertion**: Adding a new node to the list.
    - At the beginning
    - At the end
    - After a given node
- **Deletion**: Removing a node from the list.
    - From the beginning
    - From the end
    - A specific node
- **Traversal**: Accessing each node of the list.
- **Searching**: Finding a node with a specific value.

## Advantages
- Dynamic size
- Ease of insertion/deletion

## Disadvantages
- No random access
- Extra memory for storing pointers

## Common Use Cases
- Implementing stacks and queues
- Dynamic memory allocation
- Graph adjacency representation

## Example Code (Singly Linked List in C++)
```cpp
struct Node {
        int data;
        Node* next;
};

void insertAtBeginning(Node** head, int newData) {
        Node* newNode = new Node();
        newNode->data = newData;
        newNode->next = *head;
        *head = newNode;
}

void deleteNode(Node** head, int key) {
        Node* temp = *head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
                *head = temp->next;
                delete temp;
                return;
        }

        while (temp != nullptr && temp->data != key) {
                prev = temp;
                temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
}

void printList(Node* node) {
        while (node != nullptr) {
                std::cout << node->data << " ";
                node = node->next;
        }
}
```
## Additional Points

### Memory Management
- **Garbage Collection**: In languages with garbage collection, nodes are automatically deallocated.
- **Manual Deallocation**: In languages like C++, nodes must be manually deallocated to prevent memory leaks.

### Complexity Analysis
- **Insertion**: O(1) for insertion at the beginning, O(n) for insertion at the end or after a given node.
- **Deletion**: O(1) for deletion at the beginning, O(n) for deletion at the end or a specific node.
- **Traversal**: O(n)
- **Searching**: O(n)

### Advanced Operations
- **Reverse a Linked List**: Reversing the pointers of the list.
- **Detect Loop**: Using Floyd’s Cycle-Finding Algorithm.
- **Merge Two Sorted Lists**: Merging two sorted linked lists into one sorted list.

## Cheatsheet for Medium and Tough Questions

### Medium Questions
1. **Reverse a Linked List**
    ```cpp
    Node* reverseList(Node* head) {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    ```

2. **Detect a Loop in a Linked List**
    ```cpp
    bool detectLoop(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (slow != nullptr && fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true;
            }
        }
        return false;
    }
    ```
    3. **Find the Middle of a Linked List**
        ```cpp
        Node* findMiddle(Node* head) {
            if (head == nullptr) return nullptr;
            Node* slow = head;
            Node* fast = head;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
        ```

    4. **Remove N-th Node from End of List**
        ```cpp
        Node* removeNthFromEnd(Node* head, int n) {
            Node* dummy = new Node();
            dummy->next = head;
            Node* first = dummy;
            Node* second = dummy;
            for (int i = 0; i <= n; i++) {
                first = first->next;
            }
            while (first != nullptr) {
                first = first->next;
                second = second->next;
            }
            Node* toDelete = second->next;
            second->next = second->next->next;
            delete toDelete;
            return dummy->next;
        }
        ```
### Tough Questions
0. **Clone linked list**
```cpp
 Node *cloneLinkedList(Node *head) {
         if(!head) return nullptr;
         // hashmap for original -> copied
         
         unordered_map<Node*,Node*> mp;
         // step 1 : push all copied nodes in hasmap
         Node* temp = head;
         while(temp != nullptr) {
             Node* newNode = new Node(temp->data);
             mp[temp] = newNode;  // stored its copied node
             temp = temp->next;
         }
         
         // step 2 : connect all with next and random pointer
         temp = head;
         while(temp != nullptr) {
             Node* copyNode = mp[temp];    //its copy node from hashmap
             copyNode->next = mp[temp->next];  // next pointer of copyNode is next of original node
             copyNode->random = mp[temp->random]; // random pointer of copyNode is random of original node
             temp = temp->next;
         }
         return mp[head]; // return head of copied linked list
    }
```
1. **Merge Two Sorted Linked Lists**
    ```cpp
    Node* mergeTwoLists(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->data < l2->data) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
    ```

2. **Find the Intersection Point of Two Linked Lists**
    ```cpp
    Node* getIntersectionNode(Node* headA, Node* headB) {
        if (!headA || !headB) return nullptr;
        Node* a = headA;
        Node* b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
    ```
    3. **Flatten a Multilevel Doubly Linked List**
        ```cpp
        Node* flatten(Node* head) {
            if (!head) return head;
            Node* curr = head;
            while (curr) {
                if (curr->child) {
                    Node* next = curr->next;
                    Node* child = flatten(curr->child);
                    curr->next = child;
                    child->prev = curr;
                    curr->child = nullptr;
                    while (curr->next) {
                        curr = curr->next;
                    }
                    curr->next = next;
                    if (next) next->prev = curr;
                }
                curr = curr->next;
            }
            return head;
        }
        ```

    4. **Copy List with Random Pointer**
        ```cpp
        Node* copyRandomList(Node* head) {
            if (!head) return nullptr;
            Node* curr = head;
            while (curr) {
                Node* newNode = new Node(curr->data);
                newNode->next = curr->next;
                curr->next = newNode;
                curr = newNode->next;
            }
            curr = head;
            while (curr) {
                if (curr->random) {
                    curr->next->random = curr->random->next;
                }
                curr = curr->next->next;
            }
            Node* newHead = head->next;
            curr = head;
            while (curr) {
                Node* temp = curr->next;
                curr->next = temp->next;
                if (temp->next) {
                    temp->next = temp->next->next;
                }
                curr = curr->next;
            }
            return newHead;
        }
        ```

    5. **Rotate List**
        ```cpp
        Node* rotateRight(Node* head, int k) {
            if (!head || k == 0) return head;
            Node* curr = head;
            int length = 1;
            while (curr->next) {
                curr = curr->next;
                length++;
            }
            curr->next = head;
            k = k % length;
            for (int i = 0; i < length - k; i++) {
                curr = curr->next;
            }
            head = curr->next;
            curr->next = nullptr;
            return head;
        }
        ```

    6. **Sort List**
        ```cpp
        Node* merge(Node* l1, Node* l2) {
            if (!l1) return l2;
            if (!l2) return l1;
            if (l1->data < l2->data) {
                l1->next = merge(l1->next, l2);
                return l1;
            } else {
                l2->next = merge(l1, l2->next);
                return l2;
            }
        }

        Node* sortList(Node* head) {
            if (!head || !head->next) return head;
            Node* slow = head;
            Node* fast = head->next;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            Node* mid = slow->next;
            slow->next = nullptr;
            return merge(sortList(head), sortList(mid));
        }
        ```

    7. **Reorder List**
        ```cpp
        void reorderList(Node* head) {
            if (!head || !head->next) return;
            Node* slow = head;
            Node* fast = head->next;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
            }
            Node* second = slow->next;
            slow->next = nullptr;
            Node* prev = nullptr;
            while (second) {
                Node* temp = second->next;
                second->next = prev;
                prev = second;
                second = temp;
            }
            Node* first = head;
            second = prev;
            while (second) {
                Node* temp1 = first->next;
                Node* temp2 = second->next;
                first->next = second;
                second->next = temp1;
                first = temp1;
                second = temp2;
            }
        }
        ```