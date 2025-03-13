vector<int> rangeXOR(int n, vector<vector<int>>& queries) {
    vector<int> diff(n + 1, 0);

    // Step 1: Apply range updates
    for (auto& q : queries) {
        int l = q[0], r = q[1];
        diff[l] ^= 1;
        if (r + 1 < n) diff[r + 1] ^= 1;
    }

    // Step 2: Compute the final array using prefix XOR
    vector<int> result(n, 0);
    int currXOR = 0;
    for (int i = 0; i < n; i++) {
        currXOR ^= diff[i];
        result[i] = currXOR;
    }
    return result;
}
