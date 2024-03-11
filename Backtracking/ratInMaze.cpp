#include <iostream>
#include <string>
using namespace std;

void printPath(int sr, int sc, int er, int ec, string s) {
    if (sr > er || sc > ec) return;
    if (sr == er && sc == ec) {
        cout << s <<endl;
        return;
    }
    // move right
    printPath(sr, sc + 1, er, ec, s + "R");
    // move down
    printPath(sr + 1, sc, er, ec, s + "D");
}

int main() {
    int row = 3;
    int col = 3;
    printPath(0, 0, row - 1, col - 1, "");
    return 0;
}
