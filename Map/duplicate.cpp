#include <bits/stdc++.h>
using namespace std;

int main()
{
   map<string,int> mp;
   int n;
   cin >> n;
   string str;
   for(int i=0;i<n;i++) {
    cin >> str;
    mp[str]++;
   }
   auto it = mp.find("abc");
   if( it != mp.end()) {
    cout << "Present" << endl;
    mp.erase(it);
    cout << "Removed" << endl;
   }else{
       cout << "Not Present" << endl;
   }

    for (auto x : mp)
    {
        cout << x.first << " "<<x.second <<endl;
    }
    return 0;
}