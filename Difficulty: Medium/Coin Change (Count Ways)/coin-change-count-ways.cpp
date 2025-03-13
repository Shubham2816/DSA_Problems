//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
  long countWaysToMakeChangeUtil(vector<int>& arr, int ind, int T, vector<vector<long>>& dp) {
    // Base case: if we're at the first element
    if (ind == 0) {
        // Check if the target sum is divisible by the first element
        return (T % arr[0] == 0);
    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the number of ways without taking the current element
    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);
    
    // Calculate the number of ways by taking the current element
    long taken = 0;
    if (arr[ind] <= T)
        taken = countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);
        
    // Store the sum of ways in the DP table and return it
    return dp[ind][T] = notTaken + taken;
}
  
    int count(vector<int>& coins, int T) {
        // code here.
        int n = coins.size();
         vector<vector<long>> dp(n, vector<long>(T + 1, -1));
          return countWaysToMakeChangeUtil(coins, n - 1, T, dp);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends