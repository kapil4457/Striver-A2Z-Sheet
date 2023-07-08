//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.

	
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
   // Code here
        int n=grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;

        int cost=grid[0][0];
        
        while(!pq.empty()){
            int cost=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();
            
            for(int i=0; i<4; i++){
                int dr[]={-1, 0, 1, 0};
                int dc[]={0, -1, 0, 1};
                
                int nr=row+dr[i];
                int nc=col+dc[i];
                
                if(nr==n-1 && nc==n-1) return grid[nr][nc]+cost;               
                if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc]){
                    int newCost=cost+grid[nr][nc];
                    pq.push({newCost,{nr, nc}});
                    vis[nr][nc]=1;
                }
            }
        }
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends