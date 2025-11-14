class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();

        // Check if merging into exactly 1 pile is possible
        if ((n - 1) % (k - 1) != 0) return -1;
        
        // prefix sums for fast range sum
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + stones[i];

        // dp[i][j] = minimum cost to merge stones i..j
        vector<vector<int>> dp(n, vector<int>(n, 0));
        const int INF = 1e9;

        // length from k to n
        for (int len = k; len <= n; len++) {
            for (int i = 0; i + len <= n; i++) {
                int j = i + len - 1;
                dp[i][j] = INF;

                // Try splitting at m in jumps of (k-1)
                for (int m = i; m < j; m += (k - 1)) {
                    dp[i][j] = min(dp[i][j], dp[i][m] + dp[m + 1][j]);
                }

                // If this segment can be merged into 1 pile now
                if ((len - 1) % (k - 1) == 0) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }

        return dp[0][n - 1];
    }
};