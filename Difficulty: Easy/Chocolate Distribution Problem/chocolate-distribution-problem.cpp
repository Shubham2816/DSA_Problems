class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        sort(a.begin(), a.end());
    
    int i=0,j=m-1;
    int mini=INT_MAX;
    
    while(j<a.size())
    {
        int d=a[j]-a[i];
        mini= min(mini,d);
        i++;j++;
    }
    return mini;
    }
};