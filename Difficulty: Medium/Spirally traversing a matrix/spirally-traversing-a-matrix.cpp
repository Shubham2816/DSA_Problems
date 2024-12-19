//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        
        int r=matrix.size(), c=matrix[0].size();
        
         int t=0, b=r-1;
        int ri=c-1, le=0;
        vector<int>v;  // to result it out
        
        while(t<=b && le<=ri)
        {
            
            for(int i=le;i<=ri;i++)        // 1 2 3 4 
                v.push_back(matrix[t][i]);
            t++;
            
            for(int i=t;i<=b;i++)                 //8 12 16 
                v.push_back(matrix[i][ri]);
            ri--;
            
            if(t<=b)              // 0<3
            {
                for(int i=ri;i>=le;i--)  //
                v.push_back(matrix[b][i]);
                b--;
            }
            
            if(le<=ri)
            {
                for(int i=b;i>=t;i--)
                v.push_back(matrix[i][le]);
                le++;
            }
            
        }
        
        return v;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends