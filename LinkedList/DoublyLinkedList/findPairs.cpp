#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = nullptr;
    if ((*head) != nullptr)
        (*head)->prev = newNode;
    (*head) = newNode;
}

void findPairsWithGivenSum(Node* head, int sum) {
    Node* first = head;
    Node* second = head;
    while (second->next != nullptr)
        second = second->next;

    bool found = false;

    while (first != nullptr && second != nullptr && first != second && second->next != first) {
        if ((first->data + second->data) == sum) {
            found = true;
            cout << "(" << first->data << ", " << second->data << ")" << endl;
            first = first->next;
            second = second->prev;
        } else {
            if ((first->data + second->data) < sum)
                first = first->next;
            else
                second = second->prev;
        }
    }

    if (!found)
        cout << "No pair found" << endl;
}

int main() {
    Node* head = nullptr;
    insert(&head, 9);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 5);
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 1);

    int sum = 7;
    findPairsWithGivenSum(head, sum);

    return 0;
}