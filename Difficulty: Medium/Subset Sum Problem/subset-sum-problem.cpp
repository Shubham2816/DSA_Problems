//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
         int n = arr.size();
        // Create a memoization table initialized with -1 (unsolved state)
        vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
        return isSubsetSumRecursive(arr, n - 1, sum, memo);
    }
    
private:
    bool isSubsetSumRecursive(vector<int>& arr, int i, int target, vector<vector<int>>& memo) {
        // Base cases
        if (target == 0) return true;
        if (i < 0 || target < 0) return false;
        
        // Check if the subproblem has already been solved
        if (memo[i][target] != -1) {
            return memo[i][target];
        }
        
        // Exclude the current element and solve for remaining
        bool exclude = isSubsetSumRecursive(arr, i - 1, target, memo);
        
        // Include the current element (if it does not exceed the target)
        bool include = false;
        if (arr[i] <= target) 
        {
            include = isSubsetSumRecursive(arr, i - 1, target - arr[i], memo);
        }
        
        // Store the result in the memoization table
        memo[i][target] = exclude || include;
        return memo[i][target];
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
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends