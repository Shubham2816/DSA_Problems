class Solution {
  public:
    int LCIS(vector<int> &a, vector<int> &b) {
        // code here
             int n = a.size(), m = b.size();
        vector<int> dp(m, 0);
        int ans = 0;
        
        for(int i = 0; i < n; i++){
            int curr_max = 0;
            for(int j = 0; j < m; j++){
                
                if(a[i] == b[j])
                    dp[j] = max(dp[j], curr_max + 1);
                
                if(b[j] < a[i])
                    curr_max = max(curr_max, dp[j]);
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};