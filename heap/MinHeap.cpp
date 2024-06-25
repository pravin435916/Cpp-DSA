#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class MinHeap {
private:
    vector<int> heap;
    void minHeapify(int i) {
        if (i == 0) return; // If the element is the root, return

        int parent = (i - 1) / 2;
        if (heap[i] < heap[parent]) {
            swap(heap[i], heap[parent]);
            minHeapify(parent);
        }
    }

    // Helper function to heapify down
    void heapifyDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest]) {
            smallest = leftChild;
        }
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest]) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap[index], heap[smallest]);
            heapifyDown(smallest); // Recursively heapify down the affected sub-tree
        }
    }

public:
    // Insert a new element into the heap
    void insert(int value) {
        heap.push_back(value); // Add the new element to the end of the heap
        minHeapify(heap.size() - 1); // Heapify up to maintain the heap property
    }
    // Function to print the elements of the heap
    void printHeap() const {
        for (int i : heap) {
           cout << i << " ";
        }
        cout<<endl;
    }
    int leftChild(int i) {
        return 2*i+1;
    }
};

int main() {
    MinHeap heap;

    heap.insert(10);
    heap.insert(5);
    heap.insert(3);
    heap.insert(2);
    heap.insert(7);
    heap.insert(6);
    heap.insert(1);

    cout << "Heap elements after insertion: ";
    heap.printHeap();

    return 0;
}
