#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 3;
    int n = arr.size();
    int maxi = INT_MIN;

    for (int i = 0; i <= n - k; i++) {
        int sum = 0;
        for (int j = i; j < i + k; j++) {
            sum += arr[j];
        }
        maxi = max(maxi, sum);
    }

    cout << maxi << endl;
    return 0;
}
