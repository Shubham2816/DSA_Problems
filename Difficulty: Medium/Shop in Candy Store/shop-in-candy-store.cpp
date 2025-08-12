class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        int n=prices.size();
        int i=0;
        int mini=0,maxi=0;
        sort(prices.begin(),prices.end());
        while(i<n){
            mini+=prices[i];
            n=n-k;
            i++;
        }
        i=0;
        n=prices.size();
        reverse(prices.begin(),prices.end());
        while(i<n){
            maxi+=prices[i];
            n=n-k;
            i++;
        }
        return {mini,maxi};
    }
};