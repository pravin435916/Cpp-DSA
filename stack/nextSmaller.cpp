#include <iostream>
#include <vector>
#include <stack>

using namespace std;
//this is for heights return not indices
std::vector<int> nextSmallerLeft(const std::vector<int>& heights, int n) {
    std::vector<int> nsl(n, -1); // Initialize with -1, meaning no smaller element to the left
    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if (!s.empty()) {
            nsl[i] = heights[s.top()];
        }
        s.push(i);
    }

    return nsl;
}

int main() {
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    vector<int> anns = nextSmallerLeft(arr, 6);
    for (int x : anns) {
        cout << x << " ";
    }
    return 0;
}
