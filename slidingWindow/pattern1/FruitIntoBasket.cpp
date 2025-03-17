// 904. Fruit Into Baskets
// diurect problem can pick at most 2 types of fruits and each basket can have only one type of fruit

class Solution {
    public:
        int totalFruit(vector<int>& fruits) {
            int left =0;
            int right =0;
            int maxi = 0;
            unordered_map<int, int> mp;
            while(right < fruits.size()) {
                mp[fruits[right]]++;
                
                if(mp.size() > 2) { // if type size > k
                    mp[fruits[left]]--;
                    if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                    left++;
                }
                if(mp.size() <= 2) maxi = max(maxi,right-left+1);
                right++; 
            }
            return maxi;
        }
    };