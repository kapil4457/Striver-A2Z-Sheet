//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int node , vector<int>& vis,  vector<int>adj[]  , stack<int> &st){
	    vis[node]=1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            dfs(it , vis , adj , st);
	        }
	    }
	    st.push(node);
	}
	
	void dfs3(int node , vector<int>& vis , vector<int>adj[]){
	    
	    vis[node]=1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            dfs3(it , vis , adj);
	        }
	    }
	}
	
	
    int kosaraju(int V, vector<vector<int>>& adjL)
    {
        //code here
        vector<int>adj[V];
        for(auto it : adjL){
            adj[it[0]].push_back(it[1]);
        }
        // Sort all the nodes as per their finish time
            vector<int>vis(V,0);
            stack<int>st;
            for(int i =0 ; i < V ; i++){
                if(!vis[i]){
                    dfs(i , vis, adj ,st);
                }
            }
        
        // reverse the graph
        vector<int>adjT[V];
        for(int i =0 ; i < V ; i ++){
            vis[i]=0;
            for(auto it : adj[i]){
                adjT[it].push_back(i);
            }
        }
        int scc = 0;
        
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            if(!vis[node]){
                scc++;
                dfs3(node , vis , adjT);
            }
            
        }
        return scc;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t=1;
    // cin >> t;
    while(t--)
    {
    	int V=5, E=5;
    	// cin >> V >> E;

    	vector<vector<int>> adj  = {{1,0} , {0,2} , {2,1} , {0,3} , {3,4}} ;
    	// vector<vector<int>> adj(V);

    	// for(int i = 0; i < E; i++)
    	// {
    	// 	int u, v;
    	// 	cin >> u >> v;
    	// 	adj[u].push_back(v);
    	// }

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends