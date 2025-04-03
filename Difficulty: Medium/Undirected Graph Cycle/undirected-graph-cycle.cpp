//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfs(int i, int par, vector<vector<int>> &adj, vector<bool> &visited){
        visited[i] = true;
        for(auto child : adj[i]){
            if(!visited[child]){
                if(dfs(child, i, adj, visited))
                    return true;
            }
            else if(child != par)
                return true;
        }
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V); 
        for(auto x : edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        vector<bool> visited(V, false);
        
        for(int i=0;i<V;i++){
            if(!visited[i] && dfs(i, -1, adj, visited))
                return true;
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends