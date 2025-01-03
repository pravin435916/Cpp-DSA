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
int main() {
    int n, k, result;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    cin >> k;
    result = countPairs(arr, k);
    cout << "Number of pairs with difference " << k << ": " << result << endl;
    return 0;
}