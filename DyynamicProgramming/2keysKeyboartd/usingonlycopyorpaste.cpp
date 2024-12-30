class Solution {
public:
    int target;
    
    int minSteps(int n) {
        target = n;
        return findMinSteps(1, 0);
    }
    
    // Recursive function to find minimum steps to reach the target
    int findMinSteps(int current, int clipboard) {
        // Base case: if current exceeds the target, return a large number (invalid path)
        if (current > target) {
            return 1e9;
        }
        
        // If current equals the target, no more steps are needed
        if (current == target) {
            return 0;
        }
        
        // Option 1: Perform the paste operation if clipboard has content
        int pasteOption = INT_MAX;
        if (clipboard > 0) {
            pasteOption = 1 + findMinSteps(current + clipboard, clipboard);
        }
        
        // Option 2: Copy the current content
        int copyOption = INT_MAX;
        if (current > clipboard) {
            copyOption = 1 + findMinSteps(current, current);
        }
        
        // Return the minimum of the two options
        return min(copyOption, pasteOption);
    }
};
