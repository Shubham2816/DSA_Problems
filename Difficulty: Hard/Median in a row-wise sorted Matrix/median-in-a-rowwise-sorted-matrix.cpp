class Solution {
public:
    int median(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Find min and max element in matrix
        int low = mat[0][0], high = mat[0][m-1];
        for (int i = 1; i < n; i++) {
            low = min(low, mat[i][0]);
            high = max(high, mat[i][m-1]);
        }

        int desired = (n * m + 1) / 2; // position of median

        while (low < high) {
            int mid = low + (high - low) / 2;

            // count of elements <= mid
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (cnt < desired)
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};
