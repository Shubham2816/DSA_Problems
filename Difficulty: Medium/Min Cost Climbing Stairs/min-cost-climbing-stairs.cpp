//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//Back-end complete function Template for C++

class Solution {
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        // Write your code here
            int n = cost.size();
        cost.push_back(0);
        vector<int> dp(n+1,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2;i<=n;i++)
        {
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]);
        }
        int ans = dp[n];
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t-- > 0) {
        string str;
        getline(cin, str);

        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution sln;
        int res = sln.minCostClimbingStairs(arr);
        cout << res << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends