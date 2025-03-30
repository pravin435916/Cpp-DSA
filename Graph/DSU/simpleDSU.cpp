#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent;

public:
    DSU(int n) {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int i) {
        if (parent[i] != i)
            parent[i] = find(parent[i]); // Path compression
        return parent[i];
    }

    void simpleUnion(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);
        if (x_parent != y_parent)
            parent[y_parent] = x_parent;  // Attach v’s root to u’s root
    }
};

int main() {
    DSU dsu(7);
    dsu.simpleUnion(1, 2);
    dsu.simpleUnion(2, 3);
    dsu.simpleUnion(4, 5);
    dsu.simpleUnion(5, 6);
    dsu.simpleUnion(6, 7);
    dsu.simpleUnion(3, 7);

    if (dsu.find(1) == dsu.find(7))
        cout << "1 and 7 are in the same set.\n";
    else
        cout << "1 and 7 are in different sets.\n";

    return 0;
}
