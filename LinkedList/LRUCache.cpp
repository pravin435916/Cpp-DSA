class LRUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
        }
    };
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> cache;

    void InsertAfterHead(Node* node) {
        Node* curAfterHead = head->next;
        head->next = node;
        node->next = curAfterHead;
        node->prev = head;
        curAfterHead->prev = node;
    }
    void DeleteNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1; // not present
        }
        Node* node = cache[key]; // pick node
        DeleteNode(node);        // remove from last and insert at head
        InsertAfterHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            DeleteNode(node); // remove from last and insert at head
            InsertAfterHead(node);
        } else {
            //   if nhi mili then check for capacity if fulkl then remove last
            //   otherwise add
            if (cache.size() == capacity) {
                Node* node = tail->prev; // currrent our last node is at tail
                DeleteNode(node);
                cache.erase(node->key);
            }

            Node* newNode = new Node(key, value);
            InsertAfterHead(newNode);
            cache[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */