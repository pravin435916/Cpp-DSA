#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1 = {1,2,3};
    vector<int> v2 = {4,5,6};
    vector<int> v3(8);
    // sort(v1.begin(),v1.end());
    merge(v1.begin(),v1.end(),v2.begin(),v2.end(),v3.begin());
    for (auto x : v3)
    {
        cout << x << " ";
    }
    return 0;
}