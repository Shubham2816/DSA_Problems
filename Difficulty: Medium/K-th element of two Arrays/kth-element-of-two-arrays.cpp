//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(vector<int>& arr1, vector<int>& arr2, int k) {
        // code here
        vector<int>ans;
         int n=arr1.size(),m=arr2.size();

    priority_queue<int,vector<int>,greater<int>>q;
    //min heap

for(auto i: arr1) q.push(i);
for(auto i: arr2) q.push(i);


 int kthElement = -1;
    for (int i = 0; i < k; ++i) {
        if (!q.empty()) {
            kthElement = q.top();
            q.pop();
        } else {
            // Handle case where k is larger than the number of elements
            return -1; // or throw an exception
        }
}
 return kthElement;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> a, b;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            b.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(a, b, k) << endl << "~\n";
    }
    return 0;
}
// } Driver Code Ends