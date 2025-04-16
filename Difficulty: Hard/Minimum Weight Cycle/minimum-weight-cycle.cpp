//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findMinCycle(int V, vector<vector<int>>& edges) {
        // code here
         const int INF = INT_MAX / 2; // avoid overflow

        vector<vector<int>> dist(V, vector<int>(V, INF));

        vector<vector<int>> adj(V, vector<int>(V, INF));

 

        

        for (const auto &edge : edges) {

            int u = edge[0], v = edge[1], w = edge[2];

            if (w < adj[u][v]) {

                adj[u][v] = w;

                adj[v][u] = w;

                dist[u][v] = w;

                dist[v][u] = w;

            }

        }

 

        int min_cycle = INF;

        for (int k = 0; k < V; ++k) {

            

            for (int i = 0; i < k; ++i) {

                for (int j = 0; j < i; ++j) {

                    if (dist[i][j] < INF && adj[i][k] < INF && adj[k][j] < INF) {

                        int cycle_weight = dist[i][j] + adj[i][k] + adj[k][j];

                        min_cycle = min(min_cycle, cycle_weight);

                    }

                }

            }

 

            for (int i = 0; i < V; ++i) {

                for (int j = 0; j < V; ++j) {

                    if (dist[i][k] + dist[k][j] < dist[i][j]) {

                        dist[i][j] = dist[i][k] + dist[k][j];

                    }

                }

            }

        }

 

        return min_cycle == INF ? -1 : min_cycle;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({u, v, w});
            edges.push_back({v, u, w});
        }

        Solution obj;
        int res = obj.findMinCycle(V, edges);

        cout << res << endl;
    }

    return 0;
}
// } Driver Code Ends