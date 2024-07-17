#include <iostream>
#include<vector>
using namespace std;

int sumofn(int n) {
    if(n == 0) {
        return 0;
    }
    return n + sumofn(n-1);
}


int sumOfArray(vector<int> &v, int n) {
    if (n == -1) return 0;
    return v[n] + sumOfArray(v, --n);
}




int search(vector<int> v,int key,int n) {
    if(n == 0) return -1;
    if(v[n] == key) return n;
    return search(v,key,n-1);
}



bool searchCh(string v,char ch,int n) {
    if(n == -1) return false;
    if(v[n] == ch) return true;
    return searchCh(v,ch,n-1);
}
bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int findVowel(string v,int n,int i) {
    if(i == n) return -1;
    if(isVowel(v[i])) return i;
    return findVowel(v,n,i+1);
}

int main()
{
    int n =5;
    // int x = sumofn(n);
    // cout<< x ;
    vector<int> vr = {11,12,3,4,5};
    // cout<<sumOfArray(vr,n-1)<<endl;
    // cout<<search(vr,12,n);
    // cout<<searchCh("pravin",'p',n);
    cout<<findVowel("pravin",n,0);
    return 0;
}
//searching , sum of array , charcter find , vowels find , 
