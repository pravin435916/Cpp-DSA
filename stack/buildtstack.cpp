class CustomStack {
public:
   int *stack;
   int capacity;
   int size;
   int idx;
    CustomStack(int maxSize) {
        stack = new int[maxSize];
        capacity = maxSize;
        size = 0;
        idx = -1;
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == capacity;
    }
    void push(int x) {
        if(isFull()) return;
        idx++;
        size++; // to maintain size
        stack[idx] = x;
    }
    
    int pop() { // it will return the top element and decrease size
      if(isEmpty()) return -1;
      int val = stack[idx];
      idx--;
      size--;
      return val;
    }
    
    void increment(int k, int val) {
         if(isEmpty()) return;
         int mini = min(k,size);
         for(int i=0;i<mini;i++) {
            stack[i]+=val;
         }
    }
};