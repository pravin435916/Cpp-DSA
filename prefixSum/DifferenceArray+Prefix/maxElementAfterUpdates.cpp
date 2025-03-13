int maxElementAfterUpdates(int n, vector<vector<int>>& updates) {
    vector<int> diff(n + 1, 0);

    // Step 1: Apply range updates
    for (auto& upd : updates) {
        int l = upd[0], r = upd[1], val = upd[2];
        diff[l] += val;
        if (r + 1 < n) diff[r + 1] -= val;
    }

    // Step 2: Compute the final array using prefix sum
    int maxVal = 0, currSum = 0;
    for (int i = 0; i < n; i++) {
        currSum += diff[i];
        maxVal = max(maxVal, currSum);
    }
    return maxVal;
}
