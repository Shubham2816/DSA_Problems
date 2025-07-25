class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        // Code here
        int n=arr.size();
        int f=n/3;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)
        mp[arr[i]]++;
        
          vector<int>ans;
        for(auto &pr:mp){
            if(pr.second>f){
                ans.push_back(pr.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};