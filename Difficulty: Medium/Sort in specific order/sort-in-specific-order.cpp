class Solution {
  public:
    void sortIt(vector<int>& a) {
        // code here
        int n= a.size();
        vector<long long int>v1,v2;
        
        for(long long int i=0;i<n;i++)
        {
            if(a[i]%2!=0)
            {
                v1.push_back(a[i]);
                
            }
            
            else
            v2.push_back(a[i]);
            
  
        }
        sort(v1.begin(), v1.end(), greater<long long>());
        sort(v2.begin(), v2.end());
        
        for(long long int i=0;i<v1.size();i++)
    {
        a[i]=v1[i];
    }
    for(long long int i=0;i<v2.size();i++)
    {
        a[i+v1.size()]=v2[i];
    }
    }
};