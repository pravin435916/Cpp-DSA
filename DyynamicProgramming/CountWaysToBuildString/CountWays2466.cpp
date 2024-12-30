#include <vector>
#include <cstring>

class Solution {
public:
    int M = 1e9+7;

    int solve(int low, int high, int zero, int one, int len) {
        if (len > high) return 0;

        int got = 0;
        if(len >= low && len <= high) {
            got = 1;
        } 

        int addOne = solve(low, high, zero, one, len + one) % M;
        int addZero = solve(low, high, zero, one, len + zero) % M;

        return (got + addOne + addZero) % M;
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        return solve(low, high, zero, one, 0);
    }
};
