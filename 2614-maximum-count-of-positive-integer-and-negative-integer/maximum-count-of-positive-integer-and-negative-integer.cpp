class Solution {
public:
    int maximumCount(vector<int>& nums) {
    int n = nums.size();
    
    // Find the first non-negative index (first index of 0 or positive number)
    int left = 0, right = n - 1, negCount = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < 0) {
            negCount = mid + 1; // Because it's 0-based index
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // Find the first positive index (first index of number > 0)
    left = 0, right = n - 1;
    int posCount = 0;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > 0) {
            posCount = n - mid; // Count of positive numbers
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return max(negCount, posCount);
    }
};