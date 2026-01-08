class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        const int NEG = -1e9;
        
        vector<vector<int>> dp(n, vector<int>(m, NEG));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int prod = nums1[i] * nums2[j];
                
                int take = prod;
                if (i > 0 && j > 0)
                    take = max(take, prod + dp[i-1][j-1]);

                int skip1 = (i > 0) ? dp[i-1][j] : NEG;
                int skip2 = (j > 0) ? dp[i][j-1] : NEG;

                dp[i][j] = max({take, skip1, skip2});
            }
        }
        return dp[n-1][m-1];
    }
};
