#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {90,0,-4,8,12,9};
    int n = arr.size();
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-1-i;j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}