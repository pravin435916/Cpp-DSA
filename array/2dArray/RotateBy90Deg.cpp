#include <algorithm>
#include <vector>
using namespace std;

void rotateby90(vector<vector<int>> &mat)
{
    int n = mat.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each column to get the anti-clockwise rotation
    for (int i = 0; i < n / 2; i++)
    {

        swap(mat[i], mat[n - i - 1]);
    }
}