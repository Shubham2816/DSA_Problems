class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int total = 0;
        for (int num : nums) {
            total |= num;  // Step 1: Compute bitwise OR of all numbers
        }
        return total * (1 << (nums.size() - 1));  // Step 2: Multiply by 2^(n-1)
    }
};

// Initial total = 0

// Loop:

// total |= 1 → total = 1

// total |= 3 → total = 1 | 3 = 3
// (Binary: 01 | 11 = 11 → 3)

// So, after the loop: total = 3

// Step 2: Multiply by 
// 2
// \U0001d45b
// −
// 1
// 2 
// n−1
 
// n = nums.size() = 2

// So, 
// 2
// 2
// −
// 1
// =
// 2
// 2 
// 2−1
//  =2

// Return: 3 * 2 = 6