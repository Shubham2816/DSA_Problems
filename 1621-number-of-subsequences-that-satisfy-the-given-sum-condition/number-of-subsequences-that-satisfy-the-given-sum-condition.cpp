class Solution {
public:
    int mod = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size(), l = 0, r = n - 1;
        vector<int> pows(n, 1);
        // <<1 is a left shift operator which is equivalent to 2*num
        // Bit shift is comparitively faster than multiplication
        for (int i = 1 ; i < n ; ++i)
            pows[i] = (pows[i - 1]<<1) % mod;
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                res = (res + pows[r - l]) % mod;
                l++;                
            } else {
                r--;
            }
        }
        return res;
    }
};