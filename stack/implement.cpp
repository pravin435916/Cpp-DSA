implementation of a stack using an array in C++:

```
#include <iostream>

class Stack {
private:
    int* arr;
    int top;
    int capacity;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        this->top = -1;
        this->arr = new int[capacity];
    }

    ~Stack() {
        delete[] arr;
    }

    void push(int x) {
        if (top == capacity - 1) {
            std::cout << "Stack Overflow!" << std::endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            std::cout << "Stack Underflow!" << std::endl;
            return -1;
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

int main() {
    Stack stack(5);

    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << stack.pop() << std::endl;  // Output: 3
    std::cout << stack.peek() << std::endl;  // Output: 2

    return 0;
}
```

This implementation provides basic stack operations like `push`, `pop`, `peek`, `isEmpty`, and `isFull`. The `push` operation adds an element to the top of the stack, `pop` removes the top element, `peek` returns the top element without removing it, `isEmpty` checks if the stack is empty, and `isFull` checks if the stack is full.