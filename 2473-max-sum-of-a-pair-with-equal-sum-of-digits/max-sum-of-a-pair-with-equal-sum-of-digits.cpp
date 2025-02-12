class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, priority_queue<int>> mp;
        for (int i : nums) {
            int sum = 0, n = i;
            while (n) {
                sum += n % 10;
                n /= 10;
            }
            mp[sum].push(i);
        }

//  9: [36, 18],  // Max heap with top = 36
//   7: [43, 7],   // Max heap with top = 43
//   4: [13] 

        int ans = -1;
        for (auto& i : mp) {
            if (i.second.size() > 1) {
                int sum = i.second.top();
                i.second.pop();
                sum += i.second.top();
                ans = max(ans, sum);
            }
        }
        return ans;
// ans = max(54, 50) → ans = 54

    }
};