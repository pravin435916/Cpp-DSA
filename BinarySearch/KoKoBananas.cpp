class Solution {
public:
long long CalculateTime(vector<int>& piles, int h) {
    long long total =0;
    for(int pile : piles) {
            total += ceil((double)pile/h);
            // total += (pile + h - 1) / h;  // Equivalent to ceil(pile / k)
        }
    return total;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int res = right; //if it dosent any answer then its sure maxi is ans

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long long requiredTime = CalculateTime(piles, mid);

            if (requiredTime <= h) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return res;
    }
};