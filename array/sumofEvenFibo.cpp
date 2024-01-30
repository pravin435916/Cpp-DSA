#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a =0,b=1,next,sum = 0;
    for(int i=0;i<n;i++) {
        if(i <= 1) {
            next = i;
        }
        if(next % 2 == 0) {
            std::cout<<next<<" ";
            sum+=next;
        }
        a = b;
        b =next;
        next = a + b;
    }
    std::cout<<endl<<sum;
    return 0;
}