Node* mergeTwoSortedList(Node* a, Node* b) {
    if (!a) return b;
    if (!b) return a;

    Node* result;
    
    if (a->data < b->data) {
        result = a;
        result->bottom = mergeTwoSortedList(a->bottom, b);
    } else {
        result = b;
        result->bottom = mergeTwoSortedList(a, b->bottom);
    }
    
    return result;
}
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(!root || !root->next) return root;
        
        root->next = flatten(root->next); // supposing it gives the sorted list from the next node
        
        return mergeTwoSortedList(root,root->next); // simple merge two sorted list
    }