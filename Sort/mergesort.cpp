#include <iostream>
using namespace std;
void Merge(int arr[],int first,int mid,int last) {
    int n1 = mid-first+1;
    int n2 = last-mid;
    int L[n1+1];
    int R[n2+1];
    for(int i=0;i<n1;i++) {
        L[i] = arr[first+i];
    }
    for(int j=0;j<n2;j++) {
        R[j] = arr[mid+j+1];
    }
    int i=0,j=0;
    int k = first;
    while(i<n1 && j<n2){
        if(L[i] < R[j]) {
            arr[k] = L[i];
            i++;
        }else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    // Copy the remaining elements of L[], if there are any
       while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}
void MergeSort(int arr[],int first,int last) {
    if(first >= last) return;
    int mid = (first+last)/2;
    MergeSort(arr,first,mid);
    MergeSort(arr,mid+1,last);
    Merge(arr,first,mid,last);
}
int main() {
    int arr[] = {8,2,5,1,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr,0,n-1);
    cout<<"Merge Sort : ";
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}