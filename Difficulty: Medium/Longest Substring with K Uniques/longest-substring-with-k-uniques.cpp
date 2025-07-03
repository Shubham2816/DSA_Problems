class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
 unordered_map<char,int>mp;
        int ans=0;
        int i=0;
        int j=0;
        int n=s.size();
        while(j<n){
            mp[s[j]]++;
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)mp.erase(s[i]);
                i++;
            }
            if(mp.size()==k)ans=max(ans,j-i+1);
            j++;
        }
        return ans==0?-1:ans;
    }
};