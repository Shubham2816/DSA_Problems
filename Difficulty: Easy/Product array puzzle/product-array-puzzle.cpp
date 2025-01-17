//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // code here
          int n=nums.size();
          vector<long long int> l(n),r(n);
        
        l[0]=1;
        r[n-1]=1;
        
        for(int i=1;i<n;i++)
        {
            l[i]=l[i-1]*nums[i-1]; // 1 10 30 150 900
        }
        
         for(int i=n-2;i>=0;i--)
        {
            r[i]=r[i+1]*nums[i+1]; // 180 60 12 2 1
        }
        
        for(int i=0;i<n;i++)
        {
            nums[i]=l[i]*r[i];     // 180  600 360 300 900
        }
        
        return nums;
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends