//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to compute the edit distance between two strings
    int editDistance(string& s, string& t) {
        // code here
         int n = s.size(), m = t.size(), i = 0, j = 0;
        int dp[n+1][m+1];
        // to store the elsements
        for(int i = 0;i<=n;i++)    dp[i][0] = i;
        for(int i = 0;i<=m;i++)    dp[0][i] = i;
        
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=m;j++)
            {
              if(s[i-1]== t[j-1]) dp[i][j] = dp[i-1][j-1];
                
              else  dp[i][j] = 1+ min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));  
            }
        }
       return dp[n][m];
    }
};


//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends