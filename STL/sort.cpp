#include <iostream>
#include <algorithm>  // Required for std::sort
#include <climits>  // Required for std::sort
using namespace std;

int main() {
    int k = 21;
    int arr[] = {73, 192, 35, 230, 353, 154, 272, 378, 370, 378, 461, 500, 134, 361, 168, 9 ,25, 166, 419, 244, 188, 401, 394, 227 ,173, 315, 37};  // Example array
    int n = sizeof(arr)/sizeof(arr[0]);  // Calculate the size of the array

    // Sorting the array
    sort(arr, arr + n);
    for(int x : arr){
        cout<<x<<" ";
    }
    cout<<endl;
    // Printing the sorted array
    cout << "Sorted array: ";
    int mini = INT_MAX;
    int maxi = INT_MIN;
        for(int i=0;i<k;i++) {
            mini = min(arr[i],mini);
            maxi = max(arr[i],maxi);
        }
        cout<<maxi<<" "<<mini<<endl;

    return 0;
}
