class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int left = 0;
        int ct  =0;
        int sum =0;
        int wsize = 0;
        for(int right=0;right<arr.size();right++) {
            sum += arr[right];
            wsize++;
            if(wsize>= k) {
                if(sum/k >= threshold) ct++;
                sum -= arr[left];
                left++;
                wsize--;
            }
        }
        return ct;
    }
};