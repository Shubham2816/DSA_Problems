class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        // code here
         int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        // Traverse the array twice (2n - 1 to 0) to handle circular nature
        for (int i = 2 * n - 1; i >= 0; i--) {
            int curr = arr[i % n];

            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }

            // If we're in the first pass (actual array indices)
            if (i < n) {
                if (!st.empty()) {
                    ans[i] = st.top();
                } else {
                    ans[i] = -1;
                }
            }

            // Push current element to stack
            st.push(curr);
        }

        return ans;
    }
};