//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
          int s = 0;
        for(auto &i : arr){
            s += i;
        }
        
        if(s % 2 != 0) return false;
        
          int n = arr.size();
        int t = s / 2;
        
        vector<bool> dp(t + 1, 0);
        dp[0] = true;
        
        for(int nums : arr){
            for(int i = t; i >= nums; i--) {
                dp[i] = dp[i] || dp[i - nums];
            }
        }
        return dp[t];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends