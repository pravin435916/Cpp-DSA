#include <bits/stdc++.h>
using namespace std;
vector<int> MergeSortedArray(vector<int> arr,vector<int> brr) {
   vector<int> merged;
   int i = 0, j = 0;
   while(i<arr.size() && j<brr.size()) {
   if(arr[i] < brr[j]) {
    merged.push_back(arr[i]);
    i++;
   }else{
    merged.push_back(brr[j]);
    j++;
   }
   }
   while(i<arr.size()) {
    merged.push_back(arr[i]);
    i++;
   }
   while(j<brr.size()) {
    merged.push_back(brr[j]);
    j++;
   }
    return merged;
}
int main()
{
    vector<int> arr = {1,3,5};
    vector<int> brr = {2,4,6,7,8};
    vector<int> merge = MergeSortedArray(arr, brr);
    for (auto x : merge) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}