//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
   long long int mod = 1e9+7;
  
    long long int fn(int n, vector<long long int>&dp){
        if(n==0 || n==1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = ((fn(n-1,dp))%mod+(fn(n-2,dp))%mod)%mod;
    }
    
    long long int topDown(int n) {
        // code here
            
        if(n==0 || n==1) return n;
        vector<long long int>dp(n+1,-1);
        return fn(n,dp);
    }
    long long int bottomUp(int n) {
        // code here
          if(n==0 || n==1) return n;
        vector<long long int>dp(n+1,-1);
        return fn(n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends