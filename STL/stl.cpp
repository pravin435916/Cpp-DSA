#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1 = {1,2,2,3};
    vector<int> v2 = {4,5,6};
    vector<int> v3(8);
    // sort(v1.begin(),v1.end());
    // sort(arr,arr+n,greater<int>());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for (auto x : v3)
    {
        cout << x << " ";
    }
    auto last = unique(v1.begin(), v1.end());
    cout<<last<<endl;
    return 0;
}