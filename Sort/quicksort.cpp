// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int Partition(int arr[],int first,int last) {
    int pivot = arr[last];
    int i = first-1;
    for(int j=0;j<last;j++) {
    if(arr[j] < pivot) {
        i++;
        swap(arr[i],arr[j]);
    }
    swap(arr[i+1],arr[last]); // swap pivot correct position to i+1
    }
    return i+1; // return pivot index
    
}
void QuickSort(int arr[],int first,int last) {
    if(first >= last) return;
    int pivot = Partition(arr,first,last);
    QuickSort(arr,first,pivot-1);
    QuickSort(arr,pivot+1,last);
}
int main() {
    int arr[] = {8,2,5,1,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,n-1);
    cout<<"Quick Sort : ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}