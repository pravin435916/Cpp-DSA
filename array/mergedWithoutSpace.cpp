#include <bits/stdc++.h>
using namespace std;

void MergeSortedArray(vector<int> &arr, vector<int> &brr) {
    int m = arr.size();
    int n = brr.size();
    arr.resize(m + n);
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (arr[i] > brr[j]) {
            arr[k--] = arr[i--];
        } else {
            arr[k--] = brr[j--];
        }
    }

    while (j >= 0) {
        arr[k--] = brr[j--];
    }
}

int main() {
    vector<int> arr = {1, 3, 5};
    vector<int> brr = {2, 4, 6, 7, 8};
    MergeSortedArray(arr, brr);

    for (auto x : arr) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
