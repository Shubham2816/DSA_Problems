// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
         vector<int> vis(100000, 0);  
        
        queue<int> q;
        
        if(start == end) return 0;
        
        q.push(start);
        vis[start] = 1;  
        
        int steps = 0;  
        
        while (!q.empty()) {
            int size = q.size(); 
            
            for (int i = 0; i < size; i++) {
                int ele = q.front(); 
                q.pop();
                
                for (auto it : arr) {
                    int adjNode = (ele * it) % 100000;
                    if (adjNode == end) return steps + 1; 
                    
                    if (!vis[adjNode]) {
                        vis[adjNode] = 1;  
                        q.push(adjNode);  
                    }
                }
            }
            steps++;  
        }
        
        return -1;  
    }
};
