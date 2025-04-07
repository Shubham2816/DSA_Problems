class Solution {
public:
    bool func(int ind, int sum, vector<int> &nums, vector<vector<int>> &dp){
        if(sum == 0){
            return true;
        }
        if(ind == 0){
            if(nums[ind] == sum) return true;
            else return false;
        }

        if(dp[ind][sum] != -1) return dp[ind][sum];

        bool notTake = func(ind - 1, sum, nums, dp); //func(2, 11)
        bool take = false;
        if(nums[ind] <= sum){
            take = func(ind - 1, sum - nums[ind], nums, dp);
        }

        return dp[ind][sum] = (take || notTake);
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i : nums){
            sum += i;
            // int sum = 1 + 5 + 5 + 11 = 22
        }

        if(sum % 2 == 1){
            return false;
        }

        sum = sum / 2; //11

        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return func(n-1, sum, nums, dp);
// func(3, 11).
    }
};