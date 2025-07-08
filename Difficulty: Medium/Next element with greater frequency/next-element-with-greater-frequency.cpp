class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
           int n= arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
         stack<int>st;
        st.push(-1);
        for(int i=n-1;i>=0;i--)
        {
            while(st.top()!=-1&&mp[st.top()]<=mp[arr[i]]){
                st.pop();
            }
            int num=st.top();
            st.push(arr[i]);
             arr[i]=num;
        }
        return arr;
    }
};
