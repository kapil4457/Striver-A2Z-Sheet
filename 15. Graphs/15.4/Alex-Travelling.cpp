
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        // code here
        vector<pair<int,int>>adj[n+1];
        for(auto it : flights){
            adj[it[0]].push_back({it[1] , it[2]});
            
        }
        
        
        
        vector<int>cost(n+1, INT_MAX);
        cost[k]=0;
        
        priority_queue<pair<int , int > , vector<pair<int,int>> , greater<pair<int,int>> >pq;
        pq.push({0 , k});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int currCost = pq.top().first;
            
            pq.pop();
            for(auto it : adj[node]){
                if(cost[it.first]  > currCost+it.second    ||  cost[it.first]==INT_MAX ){
                    cost[it.first] = currCost+it.second;
                    pq.push({currCost+ it.second , it.first});
                }
            }
        }
        

        int ans =INT_MIN;
        for(int i =1 ; i <=n ; i ++){

        // for(auto it : cost){
            if(cost[i]==INT_MAX)return -1;
            ans = max(ans , cost[i]);
        }
        // }
        
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t=1;
    // cin >> t;
    while (t--) {
        int n=4, k=3;
        // cin >> n >> k;
        int size=3;
        // cin >> size;
        // vector<vector<int>> flights(size,vector<int>(3));
        // for (int i = 0; i < size; i++) {
        //     vector<int> temp;
        //     for (int j = 0; j < 3; ++j) {
        //         int x;
        //         cin >> x;
        //         temp.push_back(x);
        //     }
        //     flights[i]=temp;
        // }

vector<vector<int>>flights = {{2,1,1} , {2,3,1} , {3,4,1}};
        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends