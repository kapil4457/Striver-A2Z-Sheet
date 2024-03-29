//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

  void dfs(int i,int j,vector<vector<char>>&mat,vector<vector<int>>&vis,int n,int m){
    
     if (i < 0 || i >= n || j < 0 || j >= m || vis[i][j] == 1 || mat[i][j]=='X') {
        return;
    }

    vis[i][j] = 1;

    dfs(i + 1, j, mat, vis, n, m);
    dfs(i - 1, j, mat, vis, n, m);
    dfs(i, j + 1, mat, vis, n, m);
    dfs(i, j - 1, mat, vis, n, m);
}


    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
       vector<vector<char>> ans(n,vector<char>(m,'O'));
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            if(mat[i][0]=='O'){
                 dfs(i,0,mat,vis,n,m);
            }
            if(mat[i][m-1]=='O'){
                 dfs(i,m-1,mat,vis,n,m);
            }
           
           
        }
        
        for(int i=0;i<m;i++){
            if(mat[0][i]=='O')
            dfs(0,i,mat,vis,n,m);
            if(mat[n-1][i]=='O')
            dfs(n-1,i,mat,vis,n,m);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0){
                    ans[i][j]='X';
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends