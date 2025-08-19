class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
          int n = mat.size();
        int m = mat[0].size();
        
        
        int l = 0, r=n*m-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            int midVal = mat[mid/m][mid%m];
            
            if(midVal == x)
              return true;
              
            //
            int leftVal = mat[l/m][l%m];
            int rightVal = mat[r/m][r%m];
            
            
            if(leftVal <= midVal){
                if(leftVal<=x && x<midVal)
                  r = mid-1;
                else
                  l = mid+1;
            }
            else{
                if(midVal<x && x<=rightVal)
                  l = mid+1;
                else
                  r = mid-1;
            }
            
        }
        return false;
    }
};
