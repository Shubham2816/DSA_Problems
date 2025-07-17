class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        int ans = 1;

        for (int i = 0; i < n; ++i) {
            // Initialize subsequence of length 1
            dp[i] = unordered_map<int, int>();
            for (int j = 0; j < i; ++j) {
                int mod = (nums[j] + nums[i]) % k;

                // dp[j][mod] stores max length ending at j with this mod
                int len = 2;
                if (dp[j].count(mod)) {
                    len = dp[j][mod] + 1;
                }

                dp[i][mod] = max(dp[i][mod], len);
                ans = max(ans, dp[i][mod]);
            }
        }

        return ans;

    }
};