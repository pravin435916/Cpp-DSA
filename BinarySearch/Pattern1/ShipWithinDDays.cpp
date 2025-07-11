//  Problem summary : We have to paint all boards with k painters. 
// conditions : 1. Each painter can paint only one board at a time.
//              2. A painter will take time equal to the length of the board to paint it.
//              3. We have to find the minimum time required to paint all boards.
class Solution {
public:
  bool isPossible(vector<int>& arr, int k, int mid) {
    int painter = 1;  // start with first painter
    int sum = 0;
    for (int x : arr) {
        sum += x;
        if(sum > mid) {
            painter++;
            sum = x;
        }
        if(painter > k) return false;  // early optimzation
    }
    return true;
}
    int shipWithinDays(vector<int>& arr, int k) {
        // code here
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossible(arr, k, mid)) {
            result = mid;           // mid could be the answer
            high = mid - 1;      
        } else {
            low = mid + 1;          
        }
    }
    return result;
    }
};