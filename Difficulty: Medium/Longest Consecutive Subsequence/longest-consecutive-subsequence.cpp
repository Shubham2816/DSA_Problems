//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        sort(arr.begin(),arr.end());
        int ans =0;
        unordered_set<int>s,t;
        for(auto i: arr)
            s.insert(i);
        for(int i=0;i<arr.size();++i)
        {
            if(t.find(arr[i])!=t.end())
                continue;
            int count =1,temp=arr[i]+1;
            t.insert(arr[i]);
            while(s.find(temp)!=s.end())
            {
                ++count;
                ++temp;
                t.insert(temp);
            }
            ans = max(ans,count);
        }
        return ans;
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends