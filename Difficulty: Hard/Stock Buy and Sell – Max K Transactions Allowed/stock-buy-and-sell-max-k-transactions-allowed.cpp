//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int>& A, int k) {
    int N = A.size();
    if (k == 0 || N < 2) {
        return 0;
    }

    vector<vector<int>> dp(k + 1, vector<int>(N, 0));

    for (int i = 1; i <= k; i++) {
        int maxDiff = -A[0];

        for (int j = 1; j < N; j++) {
            dp[i][j] = max(dp[i][j - 1], A[j] + maxDiff);
            maxDiff = max(maxDiff, dp[i - 1][j] - A[j]);
        }
    }
    return dp[k][N - 1];
}
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends