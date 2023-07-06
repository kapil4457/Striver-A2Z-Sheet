//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    bool check(int c,int d,vector<int>adj[],vector<bool>&vis){
        if(c == d)
            return true;
        vis[c] = true;
        for(auto it:adj[c]){
            if(!vis[it]){
                if(check(it,d,adj,vis) == true)
                    return true;
            }
        }
        return false;
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int>temp;
        for(auto it:adj[c]){
            if(it == d)
                continue;
            temp.push_back(it);
        }
        adj[c] = temp;
        vector<bool>vis(V,0);
        if(check(c,d,adj,vis))  //means I can reach i.e, this is not a bridge
            return 0;
        return 1;
    }
};



//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends