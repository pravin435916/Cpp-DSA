#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<int> parent, rank; 

public:
    // Constructor to initialize DSU
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 1);  // Initialize rank with 1
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is its own parent initially
        }
    }

    // Find function with path compression
    int find(int i) {
        if (parent[i] == i) {
             return i;
        }
        return parent[i] = find(parent[i]);// Path compression
    }

    // Union function with rank optimization
    void unionByRank(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent != y_parent) {
            if (rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if (rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[y_parent] = x_parent;
                rank[x_parent]++;
            }
        }
    }
};

int main() {
    int n = 7; // Number of elements
    DSU dsu(n);

    dsu.unionByRank(1, 2);
    dsu.unionByRank(2, 3);
    dsu.unionByRank(4, 5);
    dsu.unionByRank(6, 7);
    dsu.unionByRank(5, 6);
    dsu.unionByRank(3, 7);

    // Checking if two elements belong to the same set
    if (dsu.find(1) == dsu.find(7))
        cout << "1 and 7 are in the same set.\n";
    else
        cout << "1 and 7 are in different sets.\n";

    return 0;
}
