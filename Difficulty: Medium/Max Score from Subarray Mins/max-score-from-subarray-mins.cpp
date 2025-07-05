class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
          int sum = INT_MIN;
          int n= arr.size();
        
        for(int i=0; i<n-1; i++){
            sum = max(arr[i] + arr[i+1], sum);
        }
        return sum;
    }
};