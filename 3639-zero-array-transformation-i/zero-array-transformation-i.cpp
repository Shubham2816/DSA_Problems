class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1, 0);
        for (const auto& q : queries) {
            diff[q[0]]++; // diff[l]++
            if (q[1] + 1 < nums.size())
                diff[q[1] + 1]--; // diff[r + 1]--
        }

        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            cnt += diff[i];
            if (nums[i] > cnt)
                return false;
        }
        return true;
    }
};

// nums = [2,1,2,0]
// queries = [[0,2], [1,2], [0,1]]
// Initial diff: [0, 0, 0, 0, 0]

// Query [0,2]:   diff[0]+=1, diff[3]-=1 => [1,0,0,-1,0]
// Query [1,2]:   diff[1]+=1, diff[3]-=1 => [1,1,0,-2,0]
// Query [0,1]:   diff[0]+=1, diff[2]-=1 => [2,1,-1,-2,0]

// Prefix Sum → count array:
// i=0 → 2  
// i=1 → 2+1 = 3  
// i=2 → 3-1 = 2  
// i=3 → 2-2 = 0

// Final `count` = [2,3,2,0]
// Compare with `nums`: [2,1,2,0] → ❌ → Not Equal → return `false`
