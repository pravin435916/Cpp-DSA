#include <bits/stdc++.h>
using namespace std;

int main()
{
   map<string,int> frequencyCount;
   int n;
   cin >> n;
   string str;
   for(int i=0;i<n;i++) {
    cin >> str;
    frequencyCount[str]++;
   }
   auto it = frequencyCount.find("abc");
   if( it != frequencyCount.end()) {
    cout << "Present" << endl;
    frequencyCount.erase(it);
    cout << "Removed" << endl;
   }else{
       cout << "Not Present" << endl;
   }

    for (auto x : frequencyCount)
    {
        cout << x.first << " "<<x.second <<endl;
    }
    return 0;
}