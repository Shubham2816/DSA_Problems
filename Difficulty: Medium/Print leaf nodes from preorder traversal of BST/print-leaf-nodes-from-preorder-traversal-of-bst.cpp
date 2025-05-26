class Solution {
  public:
    vector<int> leafNodes(vector<int>& arr) {
        // code here
        int n = arr.size();
          vector<int>ans;
        stack<int>st;
        st.push(arr[0]);
        for(int i=1;i<n;i++) {
            if(arr[i]<st.top()) {
                st.push(arr[i]);
            }
            else {
                int size = st.size();
                int temp = st.top();
                while(!st.empty() && arr[i]>st.top()) {
                    st.pop();
                }
                st.push(arr[i]);
                if(size > st.size()){
                    ans.push_back(temp);
                }
            }
        }
        ans.push_back(st.top());
        return ans;
    }
};