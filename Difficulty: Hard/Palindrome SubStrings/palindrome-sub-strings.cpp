class Solution {
  public:
    int countPS(string &s) {
        // code here
        int c=0;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            int l=i,r=i+1;
            while(l>=0&&r<n&&s[l]==s[r])
            {
                c++;l--;r++;
            }
            
            l=i-1,r=i+1;
             while(l>=0&&r<n&&s[l]==s[r])
            {
                c++;l--;r++;
            }
        }
        return c;
    }
};