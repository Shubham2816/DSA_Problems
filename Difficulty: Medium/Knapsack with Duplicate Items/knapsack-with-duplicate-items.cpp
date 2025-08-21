// User function Template for C++

class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int cap) {
        // code here
       int n = val.size();
        vector<int> dp(cap + 1, 0);
        
        // Initialize:
        for(int j=wt[0];j<=cap;j++)
        {
            dp[j] = (j/wt[0]) * val[0];
        }
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=cap;j++)
            {
                int notTake = dp[j];
                int take = 0;
                if(j>=wt[i]) take = dp[j-wt[i]] + val[i];
                
                dp[j] = max(take, notTake);
            }
        }
        return dp[cap];
    
    }
};