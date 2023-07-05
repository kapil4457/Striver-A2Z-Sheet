//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool isValid(int i , int j , int n , int m){
      if(i >=0 && i< n && j >= 0 && j < m)return true;
      return false;
  }
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({0,source});
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dis(n , vector<int>(m , -1));
        
        dis[source.first][source.second] = 0;
        while(!pq.empty()){
            int dist = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            
            pq.pop();

            
            if(x==destination.first && y==destination.second){
                return dist;
            }
            
            int dex[] = {1,-1,0,0};
            int dey[] = {0,0,1,-1};
            
            for(int i =0 ; i < 4 ; i ++){
                int nX = x + dex[i];
                int nY = y + dey[i];
                
                if(isValid(nX , nY , n , m) && grid[nX][nY]==1 && (dis[nX][nY]==-1 || dis[nX][nY] >  dist+1)){
                    dis[nX][nY] = dist;
                    pq.push({dist+1 , {nX,  nY}});
                }
            }
            
            
        }
        
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
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends