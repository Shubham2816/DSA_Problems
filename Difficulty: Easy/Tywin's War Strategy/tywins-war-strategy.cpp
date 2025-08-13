class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        for(int i=0;i<n;i++){
            arr[i]%=k;
            if(arr[i]!=0) arr[i]=k-arr[i];
        } 
        
         sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=0;i<(n+1)/2;i++) ans+=arr[i];
        return ans;
    }
};