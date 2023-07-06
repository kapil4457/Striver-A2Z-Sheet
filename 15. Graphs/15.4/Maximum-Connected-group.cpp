//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DS{
    vector<int>parent , size;
    public :
  DS(int n){
      parent.resize(n+1);
      size.resize(n+1 , 1);
      for(int i =0 ; i <= n ; i ++){
          parent[i] = i;
      }
  }  
  
  
  
  int findParent(int u){
      if(u==parent[u])return u;
      
      return parent[u] = findParent(parent[u]);
  }
  
  int getSize(int u){
      int ulp_u = findParent(u);
      return size[ulp_u];
  }
  
  
  void unionBySize(int u  , int v){
      int ulp_u = findParent(u);
      int ulp_v = findParent(v);
      if(ulp_u == ulp_v)return;
      
      if(size[ulp_u] < size[ulp_v]){
          size[ulp_v]+=size[ulp_u];
          parent[ulp_u] = ulp_v;
          
      }else{
           size[ulp_u]+=size[ulp_v];
           parent[ulp_v] = ulp_u;
          
      }
  }
};
class Solution {
  public:
  bool isValid(int i , int j , int n , int m){
      if(i>=0 && j>=0 && i< n && j<m)return true;
      return false;
  }
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int  row = grid.size();
        int  col = grid[0].size(); 
        int n = row;
        int m = col;
      vector<int>nodes;
      for(int i =0 ; i < n ; i ++){
          for(int j =0 ; j < n ; j ++){
              if(grid[i][j]==1){
                  int nodeVal = i*row + j;
                  nodes.push_back(nodeVal);
              }
          }
      }
      
    //   making all the islands grps
        DS ds(row * col -1 );
        for(auto node : nodes){
            int i = node/row;
            int j = node - (i*row);
            int dex[] = {0,-1};
            int dey[] = {-1,0};
            
            for(int k =0 ; k < 2 ; k++){
                int xIdx = i + dex[k];
                int yIdx = j + dey[k];
            if(xIdx >=0 && yIdx >=0){
                if(grid[xIdx][yIdx]==1){
                    int nodeVal = xIdx*row + yIdx;
                    ds.unionBySize(nodeVal , node);
                }
            }
            }
        }
        
        
        // checking for all zeros
        int ans  = INT_MIN;
        int dex[] = {1,-1,0,0};
        int dey[] = {0 , 0 , 1,-1};
        for(int i =0 ; i < n ; i ++ ){
            for(int j =0  ;j < m ; j ++){
                if(grid[i][j]==0){
                    map<int,int>ref;
                    for(int k = 0 ; k < 4 ; k ++){
                        int xIdx = i + dex[k];
                        int yIdx = j + dey[k];
                        if(isValid(xIdx , yIdx , row , col) && grid[xIdx][yIdx]==1){
                            int nodeVal = xIdx * row + yIdx;
                            int parentVal = ds.findParent(nodeVal);
                            int size = ds.getSize(parentVal);
                            ref[parentVal] = size;
                        }
                    }
                    int sum = 0;
                    for(auto it : ref){
                        sum+=it.second;
                    }
                    sum++;
                    ans = max(sum , ans);
                }
            }
        }
  if(ans == INT_MIN){
      return ds.getSize(0);
  }
  return ans;
      
      
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends