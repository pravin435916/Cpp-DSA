## Why we need this approach of Hashmap +Prefix Sum ?
So basically for subarray related problems Brute Force method takes O(n^2) time to process each subarray + extra time in processing .
But with this approach only O(n) time is taken .


Now you might wonder that what is stopping you from using Sliding window approach for such problems
Sliding window is only applicable when we know for sure if the prefixsum is an increasing or decreasing function(i.e. Monotonous in nature)
So for problems where negative input is given this approach of PrefixSum + Hashmap is the best way to solve such problems.

## Sliding window is only applicable when we know for sure if the prefixsum is an increasing or decreasing function(i.e. Monotonous in nature)