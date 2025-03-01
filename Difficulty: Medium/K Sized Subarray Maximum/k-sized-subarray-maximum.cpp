//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        vector<int>v;
        int sol = -1,a = 0;
        for(int i=0;i<=n-k;i++){
            if(sol==-1 || sol == a){
                sol = arr[i];
                int j=i+1;
                for(int b=0;b<k-1;b++,j++) if(arr[j]>sol) sol = arr[j];
            }
            else{
                if(arr[i+k-1]>sol) sol = arr[i+k-1];
            }
            v.push_back(sol);
            a = arr[i];
        }
        return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution obj;
        vector<int> res = obj.maxOfSubarrays(arr, k);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends