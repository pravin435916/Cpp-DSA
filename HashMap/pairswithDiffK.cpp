#include <vector>
#include <unordered_map>

using namespace std;

int countPairs(vector<int>& arr, int k) {
    unordered_map<int, int> mp;
    int ct = 0;
    for (int x : arr) {
        if (mp.count(x + k)) {
            ct += mp[x + k];
        }
        if (mp.count(x - k)) {
            ct += mp[x - k];
        }
        mp[x]++;
    }
    return ct;
}