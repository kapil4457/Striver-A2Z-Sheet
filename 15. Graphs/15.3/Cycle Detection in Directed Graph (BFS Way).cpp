//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
private:
	bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
		vis[node] = 1;
		pathVis[node] = 1;

		for (auto it : adj[node]) {
			if (!vis[it]) {
				if (dfsCheck(it, adj, vis, pathVis) == true)
					return true;
			}
		
			else if (pathVis[it]) {
				return true;
			}
		}

		pathVis[node] = 0;
		return false;
	}
public:
	// Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) {
// 		int vis[V] = {0};
// 		int pathVis[V] = {0};

// 		for (int i = 0; i < V; i++) {
// 			if (!vis[i]) {
// 				if (dfsCheck(i, adj, vis, pathVis) == true) return true;
// 			}
// 		}
// 		return false;
		
		
// 		BFS Way : Kahn's Algorithm
int v=  V;
vector <int> indegree(v),ans;
for(int i = 0;i < v;i++)
    for(auto it:adj[i]) indegree[it]++;
queue <int> q;
for(int i = 0;i < v;i++)
	if(indegree[i] == 0) q.push(i);
while(!q.empty()){
	int f = q.front();
	q.pop();
	ans.push_back(f);
	for(auto it:adj[f])
	    if(--indegree[it] == 0) q.push(it);
}
return ans.size() != v;
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

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends