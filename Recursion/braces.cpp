#include <bits/stdc++.h>
using namespace std;

void cointoss(int n,string ans) {
    if(n == 0) {
        cout<<ans<<endl;
        return;
    }
    char open = '(';
    char close = ')';
    int ctopen = count(ans.begin(),ans.end(),'(');
    int ctclose = count(ans.begin(),ans.end(),')');
    if(n  > ctopen) {
    cointoss(n-1,ans+'(');
    ctopen++;
    }
    if(ctclose  < ctopen) {
    cointoss(n-1,ans+')');
    ctclose++;
    }
}
int main()
{
    cointoss(3,"");
    return 0;
}