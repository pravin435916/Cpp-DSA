class Solution {
public:
   // approch :- 
   // if current rating is greater than previous rating then give one more candy than previous
    // if current rating is less than previous rating then give one more candy than next
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);

        for (int i = 1; i < n; i++)  // from left to right
            if (ratings[i] > ratings[i - 1])
                candies[i] = candies[i - 1] + 1;
        
        for (int i = n - 1; i > 0; i--) { // righh to left
            if (ratings[i - 1] > ratings[i])
                candies[i - 1] = max(candies[i] + 1, candies[i - 1]);
        }
        int ans =0;
        for(int x : candies) {
            ans += x;
        }
        return ans;
    }
};