//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
          int n = arr.size(); 
      unordered_map<int,int>map;
      vector<int>ans; 
      int count = 0; 
     for(int i = 0; i<k; i++){
         if(map[arr[i]]==0){
             count++; 
             
         }
         
         map[arr[i]]++; 
     }
     
     ans.push_back(count); 
     
     for(int i= k; i< n; i++){
         map[arr[i-k]]--; 
         if(map[arr[i-k]]==0)count--; 
        if(map[arr[i]]==0){
             count++; 
         }
         ans.push_back(count); 
         map[arr[i]]++; 
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends