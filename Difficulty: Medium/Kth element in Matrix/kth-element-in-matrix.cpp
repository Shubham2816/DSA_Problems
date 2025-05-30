class Solution {
  public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        // code here
               int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
//         int n = 4;
// int low = matrix[0][0] = 16;
// int high = matrix[3][3] = 94;

    
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            int row = n - 1, col = 0;
            
//             mid = (16 + 94) / 2 = 55
// count = 0
// row = 3, col = 0

    
            while (row >= 0 && col < n) {
                if (matrix[row][col] <= mid) {
                    count += (row + 1);
                    col++;
                } else {
                    row--;
                }
            }
    
            if (count < k) {
                low = mid + 1;  // kth element is bigger
            } else {
                high = mid;     // kth element is smaller or equal
            }
        }
    
        return low;
    }
};