#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> mp;
    vector<int> arr = {2, 7, 11, 15};
    vector<int> res;
    int target = 9;
    for (int i = 0; i < arr.size(); i++)
    {
        if (mp.find(target - arr[i]) != mp.end())
        {
            res.push_back(arr[i]);
            res.push_back(target - arr[i]);
            
        }
        else
        {
            cout << "Not Present" << endl;
        }
    }

    for (int x : res)
    {
        cout<<x<<" ";
        
    }
    return 0;
}