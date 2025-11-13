class Solution {
  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        // code here
  int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,false));
        dp[n][m] =true;
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i<n and s1[i] == s3[i+j] and dp[i+1][j]){
                    dp[i][j] = true;
                }
                else if(j<m and s2[j] == s3[i+j] && dp[i][j+1]){
                    dp[i][j] = true;
                }
            }
        }
        return dp[0][0];
    
    }
};