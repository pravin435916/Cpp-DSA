#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// Two Steps to solve
// 1.first reverse the rows 
// 2. take transpose
int main() {
	int n;
	cin>>n;
	vector<vector<int>> v(n,vector<int>(n));
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin>>v[i][j];
		}
	}
	//now reverse rows'
	for(int i=0;i<n;i++) {
			reverse(v[i].begin(),v[i].end());
	}
	//lets transpose
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			swap(v[i][j],v[j][i]);
		}
	}
	
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}