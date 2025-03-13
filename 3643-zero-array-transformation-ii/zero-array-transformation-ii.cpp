#include <vector>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
        int n = nums.size();
        vector<int> prefix(n + 1, 0);

        for (int i = 0; i < k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];
            prefix[l] += val;
            if (r + 1 < n) {
                prefix[r + 1] -= val;
            }
        }

        for (int i = 1; i <= n; i++) {
            prefix[i] += prefix[i - 1];
        }

        for (int i = 0; i < n; i++) {
            if (prefix[i] < nums[i]) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0, high = queries.size(), n = queries.size(), ans = n + 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (isZeroArray(nums, queries, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (ans > n) ? -1 : ans;
    }
};

/*
Binary Search Range
Left (low) = 1, Right (high) = 3 (total queries)
Mid = (1+3)//2 = 2
Check if nums becomes zero after first 2 queries.
Step 2: Apply First k=2 Queries
We use a difference array to efficiently apply updates.

Initialize nums

plaintext
Copy
Edit
nums = [2, 0, 2]
Process queries[0] = [0,2,1] (Decrement in range [0,2] by at most 1)

Decrease nums[0], nums[1], nums[2] as much as possible.
Optimal choice: [1, 0, 1]
plaintext
Copy
Edit
nums = [1, 0, 1]
Process queries[1] = [0,2,1] (Decrement in range [0,2] by at most 1)

Again decrease [1, 0, 1] as much as possible.
Optimal choice: [1, 0, 1]
plaintext
Copy
Edit
nums = [0, 0, 0]  ✅ Zero array achieved!
Since nums is now [0,0,0], we confirm k=2 is the smallest valid k.

Final Output:

plaintext
Copy
Edit
Output: 2*/