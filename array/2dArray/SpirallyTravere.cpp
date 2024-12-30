#include <vector>
using namespace std;

vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        int n = mat.size();    
        int m = mat[0].size(); \
        vector<int> result;

        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        while (top <= bottom && left <= right) {
            // Traverse from left to right with the top row
            for (int i = left; i <= right; i++) {
                result.push_back(mat[top][i]);
            }
            top++;

            // Traverse from top to bottom with the right column
            for (int i = top; i <= bottom; i++) {
                result.push_back(mat[i][right]);
            }
            right--;

            // Traverse from right to left across the bottom row, if still valid
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    result.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            // Traverse from bottom to top along the left column, if still valid
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    result.push_back(mat[i][left]);
                }
                left++;
            }
        }

        return result;
    }