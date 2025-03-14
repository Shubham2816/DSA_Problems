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
 if(T%arr[ind]==0) return T/arr[ind];
    return 1e9;    }
    
    // If the result for this index and target sum is already calculated, return it
    if (dp[ind][T] != -1)
        return dp[ind][T];
        
    // Calculate the number of ways without taking the current element
    long notTaken = countWaysToMakeChangeUtil(arr, ind - 1, T, dp);

    // Calculate the number of ways by taking the current element
     long taken = INT_MAX;
     if (arr[ind] <= T)
        taken = 1+countWaysToMakeChangeUtil(arr, ind, T - arr[ind], dp);
    
    // Store the sum of ways in the DP table and return it
    return dp[ind][T] = min(notTaken , taken);
}

  
    int minCoins(vector<int> &coins, int T) {
        // code here
        int n= coins.size();
         vector<vector<long>> dp(n, vector<long>(T + 1, -1)); // Create a DP table
    
    // Call the utility function to calculate the answer
    int ans=countWaysToMakeChangeUtil(coins, n - 1, T, dp);
    if(ans>=1e9) return -1;
        return ans;  
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends