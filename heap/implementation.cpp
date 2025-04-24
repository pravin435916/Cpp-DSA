#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

// Class representing a Max-Heap
class Heap {
private:
    // Vector to store heap elements
    vector<int> array;

    // Helper function to maintain the heap property
    void heapify(int i);

public:
    // Default constructor
    Heap() = default;

    // Function to insert a new key into the heap
    void insert(int key);

    // Function to extract the maximum element from the heap
    int extractMax();

    // Function to get the maximum element from the heap
    int getMax() const;

    // Function to delete a key at a given index
    void deleteKey(int i);

    // Function to increase the value of a key at a given
    // index
    void increaseKey(int i, int newValue);

    // Function to print the heap elements
    void printHeap() const;
};

// Helper function to maintain the heap property
void Heap::heapify(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int size = array.size();

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(array[i], array[largest]);
        heapify(largest);
    }
}

// Function to insert a new key into the heap
void Heap::insert(int key)
{
    array.push_back(key);
    int i = array.size() - 1;

    while (i != 0 && array[(i - 1) / 2] < array[i]) {
        swap(array[i], array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to extract the maximum element from the heap
int Heap::extractMax()
{
    if (array.size() <= 0) {
        throw underflow_error("Heap underflow");
    }

    if (array.size() == 1) {
        int root = array[0];
        array.pop_back();
        return root;
    }

    int root = array[0];
    array[0] = array.back();
    array.pop_back();
    heapify(0);

    return root;
}

// Function to get the maximum element from the heap
int Heap::getMax() const
{
    if (array.size() <= 0) {
        throw underflow_error("Heap is empty");
    }
    return array[0];
}

// Function to delete a key at a given index
void Heap::deleteKey(int i)
{
    if (i >= array.size()) {
        throw out_of_range("Invalid index");
    }

    array[i] = array.back();
    array.pop_back();
    heapify(i);
}

// Function to increase the value of a key at a given index
void Heap::increaseKey(int i, int newValue)
{
    if (i >= array.size() || array[i] >= newValue) {
        throw invalid_argument(
            "Invalid index or new value is not greater");
    }

    array[i] = newValue;
    while (i != 0 && array[(i - 1) / 2] < array[i]) {
        swap(array[i], array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to print the heap elements
void Heap::printHeap() const
{
    for (int val : array)
        cout << val << " ";
    cout << endl;
}

int main()
{
    Heap heap;

    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);
    heap.insert(45);

    cout << "Max Heap array: ";
    heap.printHeap();

    cout << "Extracted max value: " << heap.extractMax()
         << endl;
    cout << "Max Heap array after extraction: ";
    heap.printHeap();

    return 0;
}
