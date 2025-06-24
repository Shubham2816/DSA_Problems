class Solution {
  public:
    string maxSubseq(string& s, int k) {
        // code here
        int n = s.size();
        
        // stack<int>s;
        
        string sol="";
        
        for(c:s)
        {
            while(!sol.empty() && k>0 && sol.back()<c)
            {
            sol.pop_back();k--;
            }
            sol.push_back(c);
        }
        while(k--)
        {
            sol.pop_back();
        }
        return sol;
    }
};
