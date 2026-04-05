class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
        int totalSum = 0;
    for (int num : arr) totalSum += num;
    
    if ((target + totalSum) % 2 != 0 || abs(target) > totalSum)
        return 0;

    int P = (target + totalSum) / 2;
    
    vector<int> dp(P + 1, 0);
    dp[0] = 1;  // empty subset

    for (int num : arr) {
        for (int j = P; j >= num; j--) {
            dp[j] += dp[j - num];
        }
    }

    return dp[P];
    }
};