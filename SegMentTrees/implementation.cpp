#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n); // 4*n is safe size to store in aray 
        build(0, 0, n - 1, arr);
    }

    // Build the tree
    void build(int node, int start, int end, vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid, arr);
        build(2 * node + 2, mid + 1, end, arr);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    // Query in range [l, r]
    int query(int l, int r) {
        return queryUtil(0, 0, n - 1, l, r);
    }

    int queryUtil(int node, int start, int end, int l, int r) {
        // No overlap
        if (r < start || end < l) return 0;

        // Complete overlap
        if (l <= start && end <= r) return tree[node];

        // Partial overlap
        int mid = (start + end) / 2;
        int left = queryUtil(2 * node + 1, start, mid, l, r);
        int right = queryUtil(2 * node + 2, mid + 1, end, l, r);
        return left + right;
    }

    // Update index to value
    void update(int idx, int value) {
        updateUtil(0, 0, n - 1, idx, value);
    }

    void updateUtil(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid)
            updateUtil(2 * node + 1, start, mid, idx, value);
        else
            updateUtil(2 * node + 2, mid + 1, end, idx, value);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
};

// 🔷 Example usage
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree seg(arr);

    cout << "Sum of range [1, 3]: " << seg.query(1, 3) << endl; // Output: 15

    seg.update(1, 10); // arr[1] = 10

    cout << "Sum of range [1, 3] after update: " << seg.query(1, 3) << endl; // Output: 22
    return 0;
}
