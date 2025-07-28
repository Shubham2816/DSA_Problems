class Solution {
  public:
    vector<int> asciirange(string& s) {
        // code here
        vector<long long>total;
        vector<int>ans;
        long long sum = 0;
        unordered_map<int,int>m;
        for(int i=0;i<s.size();i++){
            sum+=1L*s[i];
            total.push_back(sum);
            m[s[i]]=i;
        }
        for(int i=0;i<s.size();i++){
            if(m[s[i]]!=-1 && m[s[i]]!=i && m[s[i]]!=i+1){
                ans.push_back(total[m[s[i]]]-total[i]-s[i]);
                m[s[i]]=-1;
            }
        }
        return ans; 
    }
};