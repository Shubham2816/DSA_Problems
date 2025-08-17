class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
           sort(citations.begin(), citations.end());
        int n = citations.size();
        for (int i=0; i<n; i++){
            int cit = citations[i];
            if (cit >= (n-i)) return n-i;
        }
        return 0;
    }
};