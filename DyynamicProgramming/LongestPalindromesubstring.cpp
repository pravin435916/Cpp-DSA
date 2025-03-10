
// without dp is better than dp in this case 
// #include <iostream>
// #include <vector>
// using namespace std;

// vector<vector<int>> dp; // Memoization table
// int start = 0, maxLength = 1; // Track longest palindrome substring

// // Recursive function to check if s[i...j] is a palindrome
// bool isPalindrome(int i, int j, string &s) {
//     if (i >= j) return true; // Base case: empty or single character string
//     if (dp[i][j] != -1) return dp[i][j]; // Return cached result

//     if (s[i] == s[j] && isPalindrome(i + 1, j - 1, s)) {
//         return dp[i][j] = true;
//     }
//     return dp[i][j] = false;
// }

// // Function to find the longest palindrome
// string longestPalindrome(string s) {
//     int n = s.length();
//     dp.assign(n, vector<int>(n, -1)); // Initialize memoization table

//     for (int i = 0; i < n; i++) {
//         for (int j = i; j < n; j++) {
//             if (isPalindrome(i, j, s) && (j - i + 1) > maxLength) {
//                 start = i;
//                 maxLength = j - i + 1;
//             }
//         }
//     }
//     return s.substr(start, maxLength);
// }

// int main() {
//     string s = "forgeeksskeegfor";
//     cout << "Longest Palindrome: " << longestPalindrome(s) << endl;
//     return 0;
// }


string expand(int left,int right ,string &s){
    while(left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    
    return s.substr(left+1,right-left-1);
    // to extract s.substr(start,length)format
}
string longestPalindrome(string &s) {
    if(s.empty()) return "";
    string longest = "";
    
    for(int i=0;i< s.length();i++) {
        string odd = expand(i,i,s);
        string even = expand(i,i+1,s);
        
        if(odd.length() > longest.length()) longest = odd;
        if(even.length() > longest.length()) longest = even;
    }
    return longest;
    
}