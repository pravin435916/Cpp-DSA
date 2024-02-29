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
    for (auto x : frequencyCount)
    {
        cout << x.first << " "<<x.second <<endl;
    }
    return 0;
}