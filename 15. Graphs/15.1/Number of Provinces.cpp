//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void helper(vector<int>&vis , vector<int>adj[] , int node){
      
      
      vis[node]=1;
      for(auto it : adj[node]){
          if(!vis[it]){
              helper(vis , adj , it);
          }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        
        vector<int>adjRef[V];
            int n = adj.size();
            int m = adj[0].size();
            
            for(int i =0 ; i < n ; i ++){
                for(int j =0 ; j <  m ; j  ++){
                    if(adj[i][j]==1 && i!=j){
                        adjRef[i].push_back(j);
                        adjRef[j].push_back(i);
                    }
                }
            }
        vector<int>vis(V+1 , 0);
        int cnt =0 ;
        for(int i =0 ; i < V ; i ++){
            if(!vis[i]){
                helper(vis , adjRef , i);
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends