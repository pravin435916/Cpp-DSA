    int pairsum(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        return arr[n-1] + arr[n-2];
    //     int first = INT_MIN, second = INT_MIN;
    // // Traverse the array to find the two largest elements
    // for (int num : arr) {
    //     if (num > first) {
    //         second = first; // Update second largest
    //         first = num;    // Update largest
    //     } else if (num > second) {
    //         second = num;   // Update second largest if larger than current second
    //     }
    // }

    // // Return the sum of the two largest numbers
    // return first + second;
    }