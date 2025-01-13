//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &A) {
        // code here
        int len =A.size();
        int l=0,r=len-1;
    int sol=0;
    while(l<r)
    {
        int t=min(A[l],A[r])*(r-l);
        sol=max(sol,t);
        if(A[l]<A[r])l++;
        else
        r--;
    }
    return sol;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends