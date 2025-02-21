//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxLength(string& S) {
        // code here         
        stack<int>s;
       s.push(-1);
        int sol=0;
        for(int i=0;i<S.size();i++)
        {
            if(S[i]=='(')s.push(i);
            else
            if(!s.empty())s.pop();
            else
            {
                s.pop();
            }
               if (!s.empty())
                sol = max(sol, i - s.top());
            else
                s.push(i);
        }
            return sol;

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
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends