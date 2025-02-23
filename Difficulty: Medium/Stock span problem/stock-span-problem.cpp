//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> calculateSpan(vector<int>& price) {
        // write code here
        int n= price.size();
        stack <int>s;
      vector<int>v;// for ans
      int span=0;
      s.push(0);// for the 0 day
      v.push_back(1);
      for(int i=1;i<n;i++)
      {
          while(!s.empty()&&price[s.top()]<=price[i])
          s.pop();
          if(s.empty())
          span=i+1;
          else
          span=i-s.top();
          v.push_back(span);
          s.push(i);
      }
      return v;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.calculateSpan(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends