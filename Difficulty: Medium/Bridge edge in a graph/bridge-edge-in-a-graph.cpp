//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
         vector<int>adj[V];
          for(auto it:edges) {
                 if(it[0]==c && it[1]==d || it[0]==d && it[1]==c) continue;
                  adj[it[0]].push_back(it[1]);
                  adj[it[1]].push_back(it[0]);
          }
          int vis[V]={0};
          queue<int>pq;
          vis[c]=1;
          pq.push(c);
          while(!pq.empty()) {
                int node=pq.front();
                pq.pop();
                for(auto it:adj[node]) {
                      if(!vis[it]) {
                            vis[it]=1;
                            pq.push(it);
                      }
                }
          }
           for(int i=0; i<V; i++) {
                 if(vis[d]==0) return true;
           }
           return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends