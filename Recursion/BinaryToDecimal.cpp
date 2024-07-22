#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
void helper(long long n,int p,int &res,int len) {
   if(p == len) return;
   int digit = n%10;
   res+=(digit*pow(2,p));
   helper(n/10,p+1,res,len);
}
int main() {
	long long n = 10111;
	int len =0;
	long long dup = n;
	while(dup>0) {
		len++;
		dup/=10;
	}
	int res=0;
	helper(n,0,res,len);
	cout<<res<<endl;
	return 0;
}