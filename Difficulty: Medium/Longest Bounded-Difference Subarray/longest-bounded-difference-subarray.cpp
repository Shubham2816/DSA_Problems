//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int l = 0, r = 0;
        int maxL = 0;
        int sI = 0;

        while (r < n) {
            int mine = *min_element(arr.begin() + l, arr.begin() + r + 1);
            int maxe = *max_element(arr.begin() + l, arr.begin() + r + 1);
            
            if (maxe - mine <= x) {
                if (r - l + 1 > maxL) {
                    maxL = r - l + 1;
                    sI = l;
                }
                r++; 
            } else {
                l++; 
            }
        }
        return vector<int>(arr.begin() + sI, arr.begin() + sI + maxL);
        
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends