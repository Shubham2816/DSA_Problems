class Solution {
  public:
    int get_cnt(int x,int y,vector<int> &arr){
        auto ub=upper_bound(arr.begin(),arr.end(),y);
        auto lb=lower_bound(arr.begin(),arr.end(),x);
        return ub-lb;
    }
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        sort(arr.begin(),arr.end());
        int qs=queries.size();
        vector<int> ans(qs);
        for(int i=0;i<qs;i++){
            int x=queries[i][0],y=queries[i][1];
            ans[i]=get_cnt(x,y,arr);
        }
        return ans;
    }
};