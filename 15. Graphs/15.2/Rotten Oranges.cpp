//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
      int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> temp = grid;
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt1 = 0;
        queue <pair<pair<int,int>,int>> q;
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(temp[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                if(temp[i][j]==1) cnt1++;
            }
        }
        int tm = 0;
        int cnt2 = 0;
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            vector<int> delx = {-1,0,1,0};
            vector<int> dely = {0,-1,0,1};
            for(int i =0;i<4;i++){
                int nx = r+delx[i];
                int ny = c+dely[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m &&
                !vis[nx][ny] && temp[nx][ny]==1){
                    cnt2++;
                    vis[nx][ny] = 1;
                    temp[nx][ny] = 2;
                    q.push({{nx,ny},t+1});
                    tm = max(tm,t+1);
                }
            }
        }
        if(cnt1!=cnt2) return -1;
        return tm;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends