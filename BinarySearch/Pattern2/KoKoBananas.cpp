#include <vector>
#include <algorithm>
using namespace std;
// Input: piles = [3,6,7,11], h = 8
// Output: 4
class Solution {
public:
    bool isPossibleToEat(vector<int>& piles, int mid, int h) {
        long long banana = 0;
        for(int i = 0; i < piles.size(); i++) {
            banana += piles[i] / mid;
            if(piles[i] % mid != 0) {
                banana++;
            }
        }
        return banana <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int res = -1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isPossibleToEat(piles, mid, h)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};