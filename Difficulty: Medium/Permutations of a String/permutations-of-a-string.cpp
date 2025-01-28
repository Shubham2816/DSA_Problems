//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<string> findPermutation(string &S) {
        // Code here there
        vector<string> v;
		    
		    sort(S.begin(),S.end());
		    v.push_back(S);
		    while(next_permutation(S.begin(),S.end()))// stl c++ function next permutation
		    {
		        v.push_back(S);
		    }
		    return v;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends