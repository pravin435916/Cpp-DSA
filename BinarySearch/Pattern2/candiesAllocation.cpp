class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        // brute force
        long long total = accumulate(candies.begin(), candies.end(), 0LL);
        if (k > total)
            return 0;

        int maxi = *max_element(candies.begin(), candies.end());
        int n = candies.size();
        // for (int c = maxi; c >= 1; c--) {
        //     long long count = 0;
        //     for (int i = 0; i < n; i++) {
        //         count += candies[i] / c;
        //     }
        //     if(count >= k) {
        //         return c;
        //     }
        // }
        // return 0;
        int left = 1;
        int right = maxi;
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canAllocateCandies(candies, k, mid)) {
                res = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return res;
    }

private:
    bool canAllocateCandies(vector<int>& candies, long long k, int mid) {
        long long count = 0;

        for (int i = 0; i < candies.size(); i++) {
            count += candies[i] / mid;
        }
        return count >= k;
    }
};