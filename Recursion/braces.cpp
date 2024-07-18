#include <string>
#include<iostream>
using namespace std;

void cointoss(int n,string ans) {
    if(n == 0) {
        cout<<ans<<endl;
        return;
    }
    cointoss(n-1,ans+'(');
    cointoss(n-1,ans+')');
}
int main()
{
    cointoss(3,"");
    return 0;
}