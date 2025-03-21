//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
       int solveTab(vector<int>& arr)
    {
        int n = arr.size();
        int prev2 = arr[0];
        int prev1 = max(arr[0],arr[1]);
        int curr = 0;
        for(int i=2; i<n; i++)
        {
            int include = arr[i] + prev2;
            int exclude = prev1;
            int curr = max(include,exclude);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
        
    }
    int maxValue(vector<int>& arr) {
        
        vector<int>temp1;
        vector<int>temp2;
        int n = arr.size();
        for(int i=0; i<n; i++)
        {
            if(i != 0) temp1.push_back(arr[i]);
            if(i != n-1) temp2.push_back(arr[i]);
        }
        
        return max(solveTab(temp1),solveTab(temp2));
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        int res;
        res = ob.maxValue(arr);
        cout << res << "\n"
             << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends