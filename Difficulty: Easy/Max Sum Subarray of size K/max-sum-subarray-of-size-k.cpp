class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n= arr.size();
         long ans,sum=0;
       for(int i=0;i<k;i++){
           sum+=arr[i];
       }
       ans=sum;
       int j=0;
       for(int i=k;i<n;i++){
           sum-=arr[j];
           sum+=arr[i];
           ans=max(ans,sum);
           j++;
       }
       return ans;
    }
};