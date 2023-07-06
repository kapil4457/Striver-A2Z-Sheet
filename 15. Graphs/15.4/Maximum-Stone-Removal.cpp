//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class DisjointSet{
    
    vector<int>parent , rank;
    public :
    
    DisjointSet(int n){
        parent.resize(n+1 );
        rank.resize(n+1 , 0);
        for(int i = 0 ; i <= n ; i ++){
            parent[i]=  i;
        }
    }
    
    
    
    int findParent(int u){
        if(u==parent[u])return u;
        
        return parent[u] = findParent(parent[u]);
    }
    
    
    void unionByRank(int u , int v){
        int ulp_u  = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v)return;
        
        if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};




class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here

       int maxRow = 0;
       int maxCol = 0;
       for(auto it : stones){
           maxRow = max(maxRow , it[0]);
           maxCol = max(maxCol , it[1]);
       }
       
       
       DisjointSet ds(maxRow + maxCol+1);
       unordered_map<int,int>stoneNodes;
       for(auto it : stones)
       {
           int nodeRow = it[0];
           int nodeCol = it[1] + maxRow+1;
           ds.unionByRank(nodeRow , nodeCol);
           stoneNodes[nodeRow] =1;
           stoneNodes[nodeCol] =1;
       }
       
       int cnt =0;
       for(auto it : stoneNodes){
           if(ds.findParent(it.first) == it.first){
               cnt++;
           }
       }
       
       return n-cnt;
       
       
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends