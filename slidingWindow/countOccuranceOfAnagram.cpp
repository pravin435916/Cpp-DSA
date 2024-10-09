#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
    bool checkAnagram(string pat, string txt)
    {
        sort(pat.begin(), pat.end());
        sort(txt.begin(), txt.end());
        return pat == txt;
    }

public:
    int countOccuranceOfAnagram(string pat, string txt)
    {
        int n = txt.size();
        int k = pat.length();+
        int ct = 0;
        // Sliding window approach
        for (int i = 0; i <= n - k; ++i) {
            string cur = txt.substr(i, k); // Get substring of length k starting at i
            if (checkAnagram(pat, cur)) {
                ++ct;
            }
        }
        return ct;
    }
};
int main()
{
    Solution s1;
    string txt = "forxxorfxdofr";
    string pat = "for";
    int sum = s1.countOccuranceOfAnagram(pat, txt);
    cout << sum << endl;
    return 0;
}