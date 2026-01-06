class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
          int s=0,e=0;
        int sum=0,mx=INT_MIN;
        while(e<arr.size())
        {
             sum^=arr[e];
             if(e-s+1==k)
             {
                 mx=max(mx,sum);
                 sum^=arr[s++];
             }
             e++;
        }
        return mx;
    }
};