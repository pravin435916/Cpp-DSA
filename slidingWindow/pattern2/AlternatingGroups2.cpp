class Solution
{
public:
    int numberOfAlternatingGroups(vector<int> &colors, int k)
    {
        int n = colors.size();
        int ct = 0;
        // approach 1 brute force
        // for (int i = 0; i < n; i++) {
        //      // Only start from original indices
        //     bool flag = false;
        //     for (int j = i; j < i+k - 1; j++) {
        //         // Check k-length subarrays circularly
        //         if (colors[j % n] == colors[(j+1)% n]) {
        //             flag = true;
        //             break;
        //         }
        //     }
        //     if (!flag) ct++;
        // }

        // approach 2 sliding window

        int N = n + (k - 1);
        // append k-1 elements to avoid circular issue .
        for (int i = 0; i < k - 1; i++)
        {
            colors.push_back(colors[i]);
        }

        int i = 0;
        int j = 1;
        while (j < N)
        {
            if (colors[j] == colors[j - 1])
            {
                i = j;
                j++;
                continue;
            }
            if (j - i + 1 == k)
            {
                ct++;
                i++;
            }
            j++;
        }

        return ct;
    }
};