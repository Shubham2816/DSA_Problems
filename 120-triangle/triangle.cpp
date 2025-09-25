class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.back().size();    
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int> (n));

        // base case
        for (int i = 0; i < m; i++) {
            dp[n - 1][i] = triangle.back()[i];
        }    

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < triangle[i].size(); j++) {
                // from i, j we can go to (i + 1, j) or (i + 1, j + 1)
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]) + triangle[i][j];
            }
        }

        return dp[0][0]; // the minimum value to go from 0, 0 to last row
    }
};