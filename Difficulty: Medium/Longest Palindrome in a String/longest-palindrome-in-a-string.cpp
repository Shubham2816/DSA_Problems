//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string longestPalindrome(string &S) {
        // code here
        int s=0,e=0,l,h,n=S.length();
     for(int i=0;i<n;i++)
     {
         // even part
         l=i-1;h=i;
         
         while(l>=0 && h<n && S[l]==S[h])
         {
             if(h-l+1>e)
             {
                 s=l;
                 e=h-l+1;
             }
             l--;
             h++;
         }
         
         l=i-1;
          h = i + 1;
        while(l>=0 && h<n && S[l] == S[h]){
            
            if(h - l + 1 > e){
                e = h - l + 1; //current longest pallindrome length
                s = l;
            }
            l--;
            h++;
     }
     }
       if(e == 0)return S.substr(s,1); // no pallindrome at all
    return S.substr(s,e);

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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends