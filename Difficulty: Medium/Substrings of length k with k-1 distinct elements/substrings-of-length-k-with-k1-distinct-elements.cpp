class Solution {
  public:
    int substrCount(string &S, int k) {
        // code here
         unordered_map<char,int>m;
        
        int i=0,j=0,sol=0;
        
        while(j<S.size())
        {
            
            
            m[S[j]]++;     // 97 98 99 99
            
            // now will check whether it is equal to k
            
            if(j-i+1==k)    // increasing the j frwd 0-0+1!=2
            {
                if(m.size()==k-1)// to find one sustring
                sol++;
            
            
            m[S[i]]--;      // then to remove the first word inorder to make more sub-string
            if(m[S[i]]==0)
            {
                m.erase(S[i]);
            }
            i++;
        }
        j++;
        }
        return sol;
    }
};