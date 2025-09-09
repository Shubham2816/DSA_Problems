class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
         sort(mices.begin(),mices.end());
        sort(holes.begin(),holes.end());
        
        int m=0;
        for(int i=0;i<mices.size();i++)
        {
            int sub=mices[i]-holes[i];
            
            m=max(m,abs(sub));
        }
        return m;
    }
};