class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        int left = 0, result = 0;

        for (int right = 0; right < n; ++right) {
            // Include current element
            freq[arr[right]]++;

            // Shrink window if we exceed k distinct elements
            while (freq.size() > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                left++;
            }

            // All subarrays ending at `right` with at most k distinct
            result += (right - left + 1);
        }

        return result;
    }
};