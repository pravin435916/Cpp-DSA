class Solution {
    public:
        // string shiftingLetters(string s, vector<vector<int>>& shifts) {
        //     for (auto& shift : shifts) {
        //     int start = shift[0];
        //     int end = shift[1];
        //     int direction = shift[2];
    
        //     for (int i = start; i <= end; i++) {
        //         if (direction == 1) {
        //             // Shift forward
        //             s[i] = (s[i] - 'a' + 1) % 26 + 'a';
        //         } else {
        //             // Shift backward
        //             s[i] = (s[i] - 'a' - 1 + 26) % 26 + 'a';
        //         }
        //     }
        // }
        // return s;
        // }
        string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> shift(n + 1, 0); // Difference array for range updates
    
        // Apply the difference array technique
        for (auto& shiftOp : shifts) {
            int start = shiftOp[0];
            int end = shiftOp[1];
            int direction = shiftOp[2];
            
            // Forward shift -> +1, Backward shift -> -1
            int delta = (direction == 1) ? 1 : -1;
            shift[start] += delta;
            shift[end + 1] -= delta;
        }
    
        // Compute the cumulative shifts
        int cumulativeShift = 0;
        for (int i = 0; i < n; i++) {
            cumulativeShift += shift[i];
            // Apply the shift to the character (use mod 26 for wrapping)
            s[i] = (s[i] - 'a' + cumulativeShift % 26 + 26) % 26 + 'a';
        }
    
        return s;
    }
    };