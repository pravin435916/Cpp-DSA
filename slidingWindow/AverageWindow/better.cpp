int numOfSubarrays(vector<int>& arr, int k, int threshold) {
    int sum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i]; // add current element to sum

        // When window size > k, remove the oldest element from sum:
        if (i >= k) {
            sum -= arr[i - k];
        }

        // Once we have a full window (i.e., window size = k), check average:
        if (i >= k - 1) {
            // If sum >= k * threshold, count this window
            if (sum >= k * threshold) {
                count++;
            }
        }
    }
    return count;
}
