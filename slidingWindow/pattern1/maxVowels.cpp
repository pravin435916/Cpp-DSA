class Solution {
    // 1456. Maximum Number of Vowels in a Substring of Given Length
    public:
        int maxVowels(string s, int k) {
            int left=0,maxi=INT_MIN;
            int n = s.length();
            int ct =0;
            for(int right=0;right<n;right++) {
                if(isVowel(s[right])) ct++;
                if(right-left+1 == k) {
                    maxi = max(maxi,ct);
                    if(isVowel(s[left])) ct--;
                    left++;
                }
            }
            return maxi;
        }
        private:
        bool isVowel(char ch){
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }
    };