class Solution {
public:
    int mySqrt(int x) {
        if(x == 0  || x == 1) return x;
        int st = 1;
        int end = x;
        long long mid =-1;
        while(st <= end) {
            mid = st + (end - st) / 2;
            if(mid*mid > x) {
                end = mid-1;
            }else if(mid*mid < x) {  
                st = mid+1;
            }else {
                return mid;
            }
        }
        return end;
    }
};