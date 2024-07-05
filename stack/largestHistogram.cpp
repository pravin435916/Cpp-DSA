#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


std::vector<int> nextSmallerRight(const std::vector<int>& heights) {
    int n = heights.size();
    std::vector<int> nsr(n, n); // Initialize with n, meaning no smaller element to the right
    std::stack<int> s;

    for (int i = n - 1; i >= 0; --i) { // Traverse from right to left
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if (!s.empty()) {
            nsr[i] = s.top();
        }
        s.push(i);
    }

    return nsr;
}

std::vector<int> nextSmallerLeft(const std::vector<int>& heights) {
    int n = heights.size();
   std::vector<int> nsl(n, -1); // Initialize with -1, meaning no smaller element to the left
    std::stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && heights[s.top()] >= heights[i]) {
            s.pop();
        }
        if (!s.empty()) {
            nsl[i] = s.top();
        }
        s.push(i);
    }

    return nsl;
}

int largestRectangleArea(std::vector<int>& heights) {
    int n = heights.size();
    std::vector<int> nsr = nextSmallerRight(heights);
    std::vector<int> nsl = nextSmallerLeft(heights);
    
    int max_area = 0;
    
    for (int i = 0; i < n; ++i) {
        int width = nsr[i] - nsl[i] - 1;
        int area = heights[i] * width;
        max_area = std::max(max_area, area);
    }
    
    return max_area;
}

int main() {
    std::vector<int> histogram = {2,1,5,6,2,3};
    std::cout << "Largest Rectangle Area: " << largestRectangleArea(histogram) << std::endl;
    return 0;
}
