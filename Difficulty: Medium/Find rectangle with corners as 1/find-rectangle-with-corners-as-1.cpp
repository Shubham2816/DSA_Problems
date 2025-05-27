class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& matrix) {
        // code here
        int rows = matrix.size();
    if (rows == 0) return false;
    int cols = matrix[0].size();

    // Check all pairs of rows
    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j < rows; j++) {
            int count = 0;

            // Check columns where both rows i and j have 1
            for (int k = 0; k < cols; k++) {
                if (matrix[i][k] == 1 && matrix[j][k] == 1) {
                    count++;
                    if (count >= 2) {
                        return true; // Found rectangle
                    }
                }
            }
        }
    }
    return false; // No rectangle found
    }
};