//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        int n= arr.size();
         stack<int>s;
        long long max_area=0;
        for(int i=0;i<=n;i++)
        {
            while(!s.empty()&&((i==n)||arr[i]<=arr[s.top()])){
                long long  height=arr[s.top()];
                s.pop();
                long long  width;
                if(s.empty())width =i;
                else width=i-s.top()-1;
                max_area=max(max_area,width*height);
            }
            s.push(i);
        }
        return max_area;
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
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends