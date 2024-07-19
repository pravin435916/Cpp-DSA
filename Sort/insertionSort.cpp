#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {90,0,-4,8,12,9};
    int n = arr.size();
     int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}