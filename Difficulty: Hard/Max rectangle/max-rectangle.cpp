class Solution {
  public:
    int maxArea(vector<vector<int>> &mat) {
        // code here
         int n = mat.size();
        if(n == 0) return 0;  // Handle empty matrix [web:1]
        int m = mat[0].size();  // Get column count [web:1]
        vector<int> heights(m, 0); // Heights for histogram [web:1]
        int max_area = 0;  // Initialize max area [web:1]
        for(int i = 0; i < n; ++i) {
            // Update the heights for the histogram
            for(int j = 0; j < m; ++j)
                heights[j] = mat[i][j] == 0 ? 0 : heights[j] + 1;  // Update height [web:1]
            // Compute max area for current histogram row
            stack<int> st;
            int j = 0;
            while (j < m) {
                if (st.empty() || heights[j] >= heights[st.top()]) {
                    st.push(j++);
                } else {
                    int top = st.top();
                    st.pop();
                    int width = st.empty() ? j : j - st.top() - 1;
                    int area = heights[top] * width;
                    max_area = max(max_area, area); // Update max area [web:1]
                }
            }
            // Clear remaining stack
            while (!st.empty()) {
                int top = st.top();
                st.pop();
                int width = st.empty() ? j : j - st.top() - 1;
                int area = heights[top] * width;
                max_area = max(max_area, area); // Update max area [web:1]
            }
        }
        return max_area;
    }
};