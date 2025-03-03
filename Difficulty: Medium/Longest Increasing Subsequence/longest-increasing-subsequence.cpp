//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int lis(vector<int>& a) {
        // code here
        int n = a.size();
        vector<int>temp;
        temp.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>temp.back())
             temp.push_back(a[i]);
            else{
                int idx = lower_bound(temp.begin(),temp.end(),a[i])-temp.begin();
                temp[idx]=a[i];
            }
        }
    return temp.size();

    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input

    while (t--) {
        int n;
        vector<int> arr;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            arr.push_back(num);

        Solution obj;
        cout << obj.lis(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends