#include<bits/stdc++.h>
using namespace std;

class Solution{
    public
    int kthSmallest(int arr[], int n, int k) {
        priority_queue<int> maxHeap;   //maxJHeap  Mean Top Element always gretest
        for (int i = 0; i < n; i++) {
            maxHeap.push(arr[i]);  //whenever push first make MaxHeap then after pop
            if (maxHeap.size() > k) {  //if size is greater than k pop it
                maxHeap.pop(); 
            }
        }
        return maxHeap.top();
    }
};
int main()
{
    int t;
    cin>>t;
    while(t-)
    {
        int n;
        cin>>n;
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, n k)<<endl;
    }
    return 0;
}