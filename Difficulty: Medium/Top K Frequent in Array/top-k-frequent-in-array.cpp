class Solution {
  public:
    vector<int> topKFreq(vector<int> &nums, int k) {
        // Code here
         unordered_map<int,int> mp;
         for(int i=0;i<nums.size();i++)
        mp[nums[i]]++;
        
         vector<pair<int,int>> temp;
        for ( auto it : mp)
            temp.push_back({it.second,it.first});
            
            vector<int>a;
            sort(temp.begin(),temp.end());
            
            int n=temp.size();
                for ( int i= n -1 ; i >= n-k ; i--)
            a.push_back(temp[i].second);
        
        return a;
    }
};
