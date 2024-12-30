#include<iostream>
#include<vector>
using namespace std;
// Question :- Ninja perform 3 task every day and got points for it but condition  ninja can't perfrom same task in consecutive days
// Approach :- we have to check for each day and keep track of last day 
int f(int day,int last, vector<vector<int>> points) {
    if(day ==0) {
        int maxi =0;
        for(int i=0;i<3;i++) {
          if (i != last) {
            maxi = max(maxi, points[0][i]);
          }
        }
        return maxi;
    }
    int maxi = 0;
        for(int i=0;i<3;i++) {
            if(i != last) {
              int pt = points[day][i] + f(day-1,i,points);
              maxi = max(maxi,pt);
            }
        }
    return maxi;
}
int main() {
    int n = 3;
    vector<vector<int>> points = {{1,2,5},{3,1,1},{3,3,3}};  // 11
    // int n = 2;
    // vector<vector<int>> points = {{3,9,4},{5,22,2}}; // 26
    cout<<f(n-1,-1,points)<<endl;  //passed n-1 because indexing start from 0
    // passed day as index , last task,and points
}