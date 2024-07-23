#include <iostream>
using namespace std;
//write code for combinations
void board(string s,string ans,int k,int last) {
    if(ans.size() == k) {
        cout<<ans<<endl;
        return;
    }
    if(ans.size() > k) return;
    for(int i=last;i<=s.length();i++) {
    board(s,ans+to_string(i),k,i+1);
    }
}
int main()
{
    vector<int> arr
    board("1234","",2,1);
    return 0;
}