class Solution {
    public:
    //brute force process each query and add x to all elements in the range [l,r]
    // Time complexity O(n*m) where n is the number of flights and m is the number of bookings\
    // but using difference array we can reduce it to O(n+m)
        vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
            // Difference Array + prefix sum
            // steps 
            // 1. process each query and add diff[l] += x , diff[r+1] -= x
            // 2. compute it using prefix sum
             
            vector<int> diff(n,0);
            for(int i=0;i<bookings.size();i++) {
                int l = bookings[i][0]-1; // convert 1 indexing based to 0 index
                int r = bookings[i][1]-1; // bcoz flight labels 1 to 5 not from 0 to 4
                int val = bookings[i][2];
                
                diff[l] += val;
                if(r+1 < n) diff[r+1] -= val;
            }
            int curSum =0;
            for(int i=0;i<n;i++) {
                curSum += diff[i];
                diff[i] = curSum;
            }
    
            return diff;
        }
    };

//     109. Corporate Flight Bookings
// There are n flights that are labeled from 1 to n.

// You are given an array of flight bookings bookings, where bookings[i] = [firsti, lasti, seatsi] represents a booking for flights firsti through lasti (inclusive) with seatsi seats reserved for each flight in the range.

// Return an array answer of length n, where answer[i] is the total number of seats reserved for flight i.

 

// Example 1:

// Input: bookings = [[1,2,10],[2,3,20],[2,5,25]], n = 5
// Output: [10,55,45,25,25]
// Explanation:
// Flight labels:        1   2   3   4   5
// Booking 1 reserved:  10  10
// Booking 2 reserved:      20  20
// Booking 3 reserved:      25  25  25  25
// Total seats:         10  55  45  25  25
// Hence, answer = [10,55,45,25,25]