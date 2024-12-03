class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         set<vector<int>> uniquev; 
        sort(nums.begin(), nums.end()); 
        do { uniquev.insert(nums); 
        } while (next_permutation(nums.begin(), nums.end())); 
        vector<vector<int>> res(uniquev.begin(), uniquev.end()); 
        return res;
    }
};