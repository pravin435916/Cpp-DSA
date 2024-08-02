#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// brute force
        // vector<int> res;
        // int n = arr.size();
        // int m = arr[0].size();
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         res.push_back(arr[i][j]);
        //     }
        // }
        // sort(res.begin(),res.end());
        // return res;
vector<int> mergeKSortedArrays(const vector<vector<int>>& arrays) {
    // Min-heap to store pairs of (element value, array index, element index)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;

    // Initialize heap with the first element from each array
    for (int i = 0; i < arrays.size(); ++i) {
        if (!arrays[i].empty()) {
            minHeap.push({arrays[i][0], {i, 0}});
        }
    }

    vector<int> mergedArray;
    // Extract the smallest element and add the next element from the same array to the heap
    while (!minHeap.empty()) {
        auto current = minHeap.top();
        minHeap.pop();

        // Add the smallest element to the merged array
        mergedArray.push_back(current.first);
        int i = current.second.first;  // array index 
        int j = current.second.second;  //element index

        // If there is a next element in the same array, add it to the heap
        if (j + 1 < arrays[i].size()) {
            minHeap.push({arrays[i][j + 1], {i, j + 1}});
        }
    }

    return mergedArray;
}

int main() {
    // Example input: k sorted arrays
    vector<vector<int>> arrays = {
        {1, 4, 5},
        {1, 3, 4},
        {2, 6}
    };

    // Merge the k sorted arrays
    vector<int> result = mergeKSortedArrays(arrays);

    // Print the merged array
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}
