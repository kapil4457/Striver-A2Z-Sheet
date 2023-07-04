//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i,int j,vector<vector<int>>& mat){
    if(i < 0 || j < 0 || i == mat.size() || j == mat[0].size() || !mat[i][j]) return;
    mat[i][j] = 0;
    dfs(i+1,j,mat);
    dfs(i,j+1,mat);
    dfs(i-1,j,mat);
    dfs(i,j-1,mat);
}

bool isValid(int i , int j ,int n ,int m){
    if(i <0 || j < 0 || i>=n || j >= m)return false;
    return true;
}
int numberOfEnclaves(vector<vector<int>> &grid) {
    
    // DFS
    // vector<vector<int>>mat = grid;
    // int n = mat.size(),m = mat[0].size(),ans = 0;
    // for(int i = 0;i < m;i++) if(mat[0][i]) dfs(0,i,mat);
    // for(int i = 0;i < n;i++) if(mat[i][0]) dfs(i,0,mat);
    // for(int i = 0;i < m;i++) if(mat[n-1][i]) dfs(n-1,i,mat);
    // for(int i = 0;i < n;i++) if(mat[i][m-1]) dfs(i,m-1,mat);
    // for(int i = 1;i < n-1;i++){
    //     for(int j = 1;j < m-1;j++)
    //         if(mat[i][j]) ans++;
    // }
    // return ans;
    
    
    // BFS
    
    
      int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if((i==0 or i==n-1 or j==0 or j==m-1) and grid[i][j]==1 )
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int delx[]={-1,0,1,0};
        int dely[]={0,1,0,-1};
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int nr=row+delx[i];
                int nc=col+dely[i];
                if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and grid[nr][nc]==1)
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] and grid[i][j]==1)
                {
                    count++;
                }
            }
        }
        return count;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends