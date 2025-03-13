
// 3306. Count of Substrings Containing Every Vowel and K Consonants II

// Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

 

// Example 1:

// Input: word = "aeioqq", k = 1

// Output: 0

// Explanation:

// There is no substring with every vowel.

// Example 2:

// Input: word = "aeiou", k = 0

// Output: 1

// Explanation:

// The only substring with every vowel and zero consonants is word[0..4], which is "aeiou".

// Example 3:

// Input: word = "ieaouqqieaouqq", k = 1

// Output: 3
class Solution {
    public:
        long long countOfSubstrings(string word, int k) {
            unordered_map<char, int> mp;
            int vowelCount = 0, consonantCount = 0;
            int left = 0, n = word.size();
            long long res = 0;
    
            //fill next consonent
            vector<int> nextCons(n,n);
            int lastConsIdx = n;
            for(int i=n-1;i>=0;i--) {
                nextCons[i] = lastConsIdx;
                if(!isVowel(word[i])) {
                    lastConsIdx = i;
                }
            }
    
            for (int right = 0; right < n; right++) {
                char ch = word[right];
    
                if (isVowel(ch)) {
                     mp[ch]++; 
                } else {
                    consonantCount++;
                }
    
                // Shrink the window if consonant count exceeds k
                while (consonantCount > k) {
                    char leftChar = word[left];
                    if (isVowel(leftChar)) {
                        mp[leftChar]--;
                        if(mp[leftChar] == 0) mp.erase(leftChar);
                    } else {
                        consonantCount--;
                    }
                    left++;
                }
                
                while(mp.size() == 5 && consonantCount == k) {
                   int nextIdx = nextCons[right];
                   res += (nextIdx - right);
                   char leftChar = word[left];
                    if (isVowel(leftChar)) {
                        mp[leftChar]--;
                        if(mp[leftChar] == 0) mp.erase(leftChar);
                    } else {
                        consonantCount--;
                    }
                    left++;
                }
            }
    
            return res;
        }
        private:
        bool isVowel(char ch){
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        }
    };