#include <iostream>
#include <unordered_map>
#include<string>
using namespace std;
    string removeDups(string str) {
        unordered_map<char, int> mp;
        string ans = "";
        
        for (char ch : str) {
           if(mp.find(ch) == mp.end()){
              ans+=ch;
              mp[ch] = 1;
           }
        }
        return ans;

        // set<char> seen;
        // string ans = "";
        
        // for (char ch : str) {
        //     if (seen.find(ch) == seen.end()) {
        //         ans += ch;
        //         seen.insert(ch);
        //     }
        // }
    }
int main() {
    cout<<removeDups("zvvo");
}
