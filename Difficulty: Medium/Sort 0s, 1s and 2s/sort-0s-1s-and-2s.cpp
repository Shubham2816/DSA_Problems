class Solution {
  public:
    void sort012(vector<int>& a) {
        // code here
        int i=0, j=0,k=a.size()-1;
    while(i<=k)
    {
        if(a[i]==0)
        {
            swap(a[i++],a[j++]);
        }
        
        else if (a[i]==2) 
                swap(a[i],a[k--]);
            else
                i++;
    }
    }
};