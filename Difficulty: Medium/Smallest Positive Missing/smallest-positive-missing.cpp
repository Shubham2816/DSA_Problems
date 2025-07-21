class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
             int n=arr.size();
      unordered_map<int,int> ans;
      for(int i=0;i<n;i++){
          ans[arr[i]]++;
      }

 int i=1;
      while(1){
          if(ans[i]==0)
          return i;
          i++;
      }
      return -1;
    }
};