class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
         for(int i=0; i<mat.size(); i++){
            int j = mat[i].size() - 1 - i;
            int temp = mat[i][i];
            mat[i][i] = mat[i][j];
            mat[i][j] = temp;}
    }
};
