#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  bool isPossibleToAllocate(vector<int> &arr, int k, int mid) {
    int student = 1;  // start with first student
    int sum = 0;
    for (int x : arr) {
        sum += x;
        if(sum > mid) {
            student++;
            sum = x;
        }
        if(student > k) return false;  // early optimization
    }
    return true;
}
    int findPages(vector<int> &arr, int k) {
 int n = arr.size();
    if (k > n) return -1; // Edge case: more students than books

    int low = *max_element(arr.begin(), arr.end()); // Largest single book
    int high = accumulate(arr.begin(), arr.end(), 0); // Sum of all books
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (isPossibleToAllocate(arr, k, mid)) {
            result = mid; 
            high = mid - 1; 
        } else {
            low = mid + 1; 
        }
    }
    return result;
    }
};


int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}