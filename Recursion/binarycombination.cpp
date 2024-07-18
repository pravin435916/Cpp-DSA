#include <iostream>
using namespace std;

void cointoss(int n,string ans) {
    if(n ==  0) {
        cout<<ans<<endl;
        return;
    }
    //dont print consecutive 1 
    //so if phle 1 ki call lgi hai then mt lagao
    if(ans[ans.length()-1] != '1' || ans.length() == 0){
    cointoss(n-1,ans+'1');
    }
    cointoss(n-1,ans+'0');
}
int main()
{
    cointoss(3,"");
    return 0;
}