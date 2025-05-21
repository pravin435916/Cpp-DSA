#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pii; // {value, {row, col}}

vector<int> smallestRange(vector<vector<int>>& nums) {
    int k = nums.size();
    int n = nums[0].size(); // assuming all lists are same length

    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
    int maxi = INT_MIN;
    
    // Step 1: Initialize the heap with first elements
    for (int i = 0; i < k; i++) {
        int val = nums[i][0];
        minHeap.push({val, {i, 0}});
        maxi = max(maxi, val);
    }

    int rangeStart = 0, rangeEnd = INT_MAX;

    // Step 2: Process the heap
    while (true) {
        auto [mini, p] = minHeap.top();
        int row = p.first;
        int col = p.second;
        minHeap.pop();

        // Update range if current is smaller
        if (maxi - mini < rangeEnd - rangeStart) {
            rangeStart = mini;
            rangeEnd = maxi;
        }

        // If we’ve reached the end of one list, break
        if (col + 1 == nums[row].size()) break;

        // Push next element from the same list
        int nextVal = nums[row][col + 1];
        minHeap.push({nextVal, {row, col + 1}});
        maxi = max(maxi, nextVal);
    }

    return {rangeStart, rangeEnd};
}

int main() {
    vector<vector<int>> arr = {
        {4, 7, 9, 12, 15},
        {0, 8, 10, 14, 20},
        {6, 12, 16, 30, 50}
    };

    vector<int> result = smallestRange(arr);
    cout << "[" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
