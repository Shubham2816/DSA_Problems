class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        vector<int> px(n, 0), py(n, 0);
         //total X count , total Y count


        for (int i = 0; i < m; i++) {
            int rowX = 0, rowY = 0;
           //current row ka running prefix
           
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X') rowX++;
                else if (grid[i][j] == 'Y') rowY++;

                px[j] += rowX;
                py[j] += rowY;

                if (px[j] == py[j] && px[j] > 0) {
                    ans++;
                }
            }
        }

        return ans;
    }
};