#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;
// Input: arr = [2, 1, 8]
// Output: 1
// Explanation: left smaller array ls = [0, 0, 1], right smaller array rs = [1, 0, 0]. Maximum Diff of abs(ls[i] - rs[i]) = 1
int maxAbsDifference(vector<int>& arr) {
    int n = arr.size();
    vector<int> left_smaller(n, 0), right_smaller(n, 0);
    stack<int> st;

    // Fill left_smaller array
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            left_smaller[i] = st.top();
        } else {
            left_smaller[i] = 0;
        }
        st.push(arr[i]);
    }

    // Clear the stack for the next use
    while (!st.empty()) {
        st.pop();
    }

    // Fill right_smaller array
    for (int i = n - 1; i >= 0; --i) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            right_smaller[i] = st.top();
        } else {
            right_smaller[i] = 0;
        }
        st.push(arr[i]);
    }

    // Calculate the maximum absolute difference
    int max_diff = 0;
    for (int i = 0; i < n; ++i) {
        int diff = abs(left_smaller[i] - right_smaller[i]);
        max_diff = max(max_diff, diff);
    }

    return max_diff;
}

int main() {
    vector<int> arr = {2, 4, 8, 7, 7, 9, 3};
    cout << "Maximum Absolute Difference: " << maxAbsDifference(arr) << endl;
    return 0;
}
