#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> arr = {90,0,-4,8,12,9};
    int n = arr.size();
    int min;
    for(int i=0;i<n-1;i++) {
        min =i;
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[min]) {
              min = j;
            }
        }
        if(min != i) {
            swap(arr[min],arr[i]);
        }
    }
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}