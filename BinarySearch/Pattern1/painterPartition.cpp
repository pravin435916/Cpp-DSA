class Solution {
  public:
  bool isPossible(vector<int>& arr, int k, int mid) {
    int painter = 1;  // start with first student
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
    int minTime(vector<int>& arr, int k) {
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