//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Disjoint{
  vector<int>rank , parent;
  public :
  Disjoint(int n){
      rank.resize(n+1 , 0);
      parent.resize(n+1);
      for(int i = 0 ; i < n ; i ++){
          parent[i] = i;
      }
  }  
  
  int findParent(int u){
      if(u == parent[u]){
          return u;
      }
      return parent[u] = findParent(parent[u]);
  }
  
  
  void unionByRank(int u , int v){
      int ulp_u = findParent(u);
      int ulp_v = findParent(v);
      
      if(ulp_u==ulp_v)return;
      if(rank[ulp_u] < rank[ulp_v]){
          parent[ulp_u] = ulp_v;
        //   rank[ulp_v]++;
      }else if(rank[ulp_u]  > rank[ulp_v]){
          parent[ulp_v] = ulp_u;
        //   rank[ulp_u]++;
      }else{
          
          parent[ulp_v] = ulp_u;
          rank[ulp_u]++;
      }
  }
  
};
class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        Disjoint ds(n);
        int extras =0;
        
        for(auto it : edge){
            int first = it[0];
            int second= it[1];
            
            if(ds.findParent(first) == ds.findParent(second)){
                extras++;
            }else{
                ds.unionByRank(first , second);
            }
        }
        int cntC = 0;
        
        for(int i = 0 ; i < n ; i ++){
            if(ds.findParent(i) == i){
                cntC++;
            }
        }
        
        
        if(cntC-1 <= extras)return cntC-1;
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends