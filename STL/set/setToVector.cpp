#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
    string kthDistinct(vector<string>& arr, int k) {
        // 1. Using Map
        // unordered_map<string,int> mp;
        // for(string s : arr) {
        //     mp[s]++;
        // } //stored the frequency
        // int count =0;
        // for(auto s : arr) {
        //     if (mp[s] == 1) {  //frequency 1 then count => d a
        //         count++;
        //         if (count == k) { //k = 2 1st d then 2nd a then a is answer
        //             return s;
        //         }
        //     }
        // }
        // return "";
        // 2.using Set
        unordered_set<string> set;
        vector<string> seen;
        for (string s : arr) {
            if (set.find(s) == set.end()) {
                seen.push_back(s);
                cout<<s<<endl;
            }
            set.insert(s);
        }
        // Check if k is out of bounds
        if (k <= 0 || k > seen.size()) {
            return "";
        }

        return seen[k - 1];
    }
    int main() {
        vector<string> arr = {"d","b","c","b","c","a"};
        int k = 2;
        cout<<kthDistinct(arr,k);

    }