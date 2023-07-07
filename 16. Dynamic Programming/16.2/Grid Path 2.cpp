//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


#define ll long long int
int mod = 1e9+7;

class Solution {
  public:
  
  int f(int x , int y , vector<vector<int>>&grid , vector<vector<ll>>&dp){
      if(x==0 && y==0 && grid[x][y]==0)return 1;
      if(x < 0 || x>= grid.size() || y < 0|| y >= grid[0].size())return 0;
      if(grid[x][y]==1)return 0;
      if(dp[x][y]!=-1)return dp[x][y];
      int up = f(x-1 , y , grid ,dp)%mod;
      int left = f(x , y-1 , grid,dp)%mod;
      return dp[x][y] = (left+up)%mod;
  }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<ll>>dp(n , vector<ll>(m,-1));
        return f(n-1 , m-1 , grid , dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends