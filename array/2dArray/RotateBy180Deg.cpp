#include <vector>
#include <algorithm>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat) {
       int n = mat.size();
       int m = mat[0].size();
       
       for(int i=0;i<n;i++) {
           reverse(mat[i].begin(),mat[i].end());
       }
       
       for(int i=0;i<n/2;i++) {
           swap(mat[i],mat[n-i-1]);
       }
    }