#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin>>N;
    while(N--) {
	int T;
	cin>>T;
	int arr[T];
    for(int i=0;i<T;i++) {
        cin >> arr[i];
    }
    sort(arr,arr+T);
    int mins = INT_MAX;
    for(int i=1;i<T;i++) {
        int mine = arr[i] - arr[i-1];
         mins = min(mine,mins);
    }
     cout << mins << endl;  
    }
	return 0;
}

