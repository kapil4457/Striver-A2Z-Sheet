//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        
        vector<pair<long long int,long long int>>adj[n];
        for(auto it : roads){
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }
        
        
        vector<long long >dist(n , INT_MAX) , ways(n,0);
        dist[0]=0;
        ways[0]=1;
        
        priority_queue<pair<long long int,long long int> , vector<pair<long long int , long long int> > , greater<pair<long long int , long long int>> >pq;
        pq.push({0 ,0});
        
        long long  mod = (int)(1e9+7);
        while(!pq.empty()){
            long long int node = pq.top().second;
            long long int dis = pq.top().first;
            
            pq.pop();
            
            
        
            for(auto it : adj[node]){
                long long int n = it.first;
                long long int d = it.second;
                
                if(dist[n] > d+dis){
                    pq.push({d+dis , n});
                    dist[n] = d+dis;
                    ways[n] = ways[node];
                }else if(dis+d == dist[n]){
                    ways[n] =( ways[n]+ways[node] )%mod;
                }
            }
            
        }
        
        return ways[n-1]%mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends