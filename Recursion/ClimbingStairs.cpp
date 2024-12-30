class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;

        int prev1 = 3;
        int prev2 = 2;
        int cur = 0;

        for (int i = 3; i < n; i++)
        {
            cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }

        return cur;
    }
};
// recursiom solution
class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 3)
            return n;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

// top down
int solve(int n, vector<int> &dp)
{
    if (n <= 2)
        return n;
    if (dp[n] != -1)
        return dp[n];
    dp[n] = solve(n - 1, dp) + solve(n - 2, dp);
    return dp[n];
}
int climbStairs(int n)
{
    if (n <= 2)
        return n;
    vector<int> dp(n + 1, -1);
    return solve(n, dp);
}
