
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    void dfs(vector<int>adj[] , int currNode , bool& ans , int parent , vector<int>&vis){
        
        if(vis[currNode]){
            ans = true;
            return;
        }
        vis[currNode]=1;
        
        for(auto it : adj[currNode] ){
            if(it!=parent){
            dfs(adj , it , ans , currNode , vis);
            }
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        // DFS
        
        // bool  ans = false;
        // vector<int>vis(V,0);
        // for(int i = 0 ; i < V ; i++){
        //     if(!vis[i]){
        // dfs(adj , i ,ans , -1 , vis);
                
        //     }
        // }
        // return ans;
        
        
        
        // BFS
        
        vector<int>vis(V,0);
        for(int i =0 ; i < V ; i ++){
            if(!vis[i]){
                
                queue<pair<int,int>>q;
                q.push({i , -1});
                
                
                while(!q.empty()){
                    
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    if(vis[node])return true;
                    vis[node] = 1;
                    
                    for(auto it : adj[node]){
                        if(it!=parent){
                            
                        q.push({it , node});
                        }
                    }
                    
                }
                
            }
        }
        
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends