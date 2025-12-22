// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
          int m = arr[0].size();
        int n = arr.size();
        
        int row = 0 , col = m-1;
        int maxi = INT_MIN;
        int ans = -1;
        
        while(row<n && col>=0){
            
            if(arr[row][col] == 1){
                int need = m-col;
                if(need>maxi){
                    maxi = need;
                    ans = row;
                }
                col--;
            }else{
                row++;
            }
        }
        
        return ans;
    }
};