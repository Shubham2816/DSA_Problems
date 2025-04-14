//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
        // Code here
         vector<int>vis(V,1e8);
        vis[S]=0;
        
        for(int i=0;i<V-1;i++)
        {
            for( auto i:edges)
            {
                int u=i[0];
                int v=i[1];
                int w=i[2];
                if (vis[u] != 1e8 && vis[u] + w < vis[v]) {
					vis[v] = vis[u] + w;
				}
            }
        }
        
        // Nth relaxation to check negative cycle
		for (auto it : edges) {
			int u = it[0];
			int v = it[1];
			int w = it[2];
			if (vis[u] != 1e8 && vis[u] + w < vis[v]) {
				return { -1};
			}
		}


		return vis;
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int> > edges;

        for (int i = 0; i < E; ++i) {
            int u, v, w;
            cin >> u >> v >> w;

            vector<int> edge(3);
            edge[0] = u;
            edge[1] = v;
            edge[2] = w;
            edges.push_back(edge);
        }

        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.bellmanFord(V, edges, src);

        for (size_t i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends