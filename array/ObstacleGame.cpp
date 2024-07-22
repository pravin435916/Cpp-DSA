// Sample Input
// 4 4 5 20
// . . * .
// . # . .
// * * . .
// . # * *
// Sample Output
// Yes
// 13
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m, k, s;
    cin >> n >> m >> k >> s;
    vector<vector<char>> v(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    // Traverse the park
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == '.') {
                if(j == m-1) s-=2;  //if last col then decrease by 2 
                else s -= 3;
            } else if (v[i][j] == '*') {
                s += 5;
                s--;
            } else if (v[i][j] == '#') {
                break; // Jump to next row
            }
            if (s < k) {
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes" << endl;
    cout << s << endl;

    return 0;
}
