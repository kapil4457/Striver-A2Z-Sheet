//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
          vector<pair<int,int>>adj[N];
        
        for(auto it : edges){
           adj[it[0]].push_back({it[1] , it[2]});
        }
        vector<int>dis(N , -1);
        dis[0]= 0 ;
        
        queue<pair<int,int>>q;
        q.push({0, 0});
        
        
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            
            q.pop();
            
            
            for(auto it : adj[node]){
                int n = it.first;
                int d = it.second;
                if(dis[n]==-1){
                    dis[n]=dist+d;
                    q.push({n , dist+d});
                }else{
                    if(dis[n]  > dist+d){
                        dis[n] = dist+d;
                        q.push({n , dist+d});
                    }
                }
            }
            
            
        }
        
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends