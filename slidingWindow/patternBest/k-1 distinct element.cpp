// Substrings of length k with k-1 distinct elements
class Solution {
  public:
    int substrCount(string &s, int k) {
        int n = s.length();
        if (k > n) return 0;

        unordered_map<char, int> freq;
        int left = 0, count = 0;
        int distinct = 0;

        for (int right = 0; right < n; right++) {
            // Add current character to map
            freq[s[right]]++;
            if (freq[s[right]] == 1)
                distinct++;

            // Maintain window of size k
            if (right - left + 1 > k) {
                freq[s[left]]--;
                if (freq[s[left]] == 0)
                    distinct--;
                left++;
            }

            // Check for valid window
            if (right - left + 1 == k && distinct == k - 1) {
                count++;
            }
        }

        return count;
    }
};