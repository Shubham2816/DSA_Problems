class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
         int n = arr.size();
        int sol = 0;
        for(int i=0;i<n;i++){
            long freq = (long)(i+1)*(n-i);
            if(freq%2 != 0) sol ^=arr[i];
        }
        return sol;
    }
};