#include <iostream>
using namespace std;

void cointoss(int n,string ans) {
    if(n ==  0) {
        cout<<ans<<endl;
        return;
    }
    if(ans[ans.length()-1] != 'H' || ans.length() == 0) {
    cointoss(n-1,ans+'H');
    }
    cointoss(n-1,ans+'T');
}
int main()
{
    cointoss(3,"");
    return 0;
}