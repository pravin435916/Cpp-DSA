#include <iostream>
using namespace std;

int main() {
    int arr[] = {8,0,0,1,0,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int nonZeroIndex = 0;
    for(int i=0;i<n;i++) {
       if (arr[i] != 0) {
            swap(arr[nonZeroIndex], arr[i]);
            nonZeroIndex++;
        }
    }
    cout<<"zero at last : ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}