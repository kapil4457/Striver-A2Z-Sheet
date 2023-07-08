//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int f(int ind , int currW , int val[] , int wt[] , vector<vector<int>>&dp){
    if(ind==0)return ((int)(currW/wt[0])) * val[0];

if(dp[ind][currW]!=-1)return dp[ind][currW];
    int not_take = 0 + f(ind-1 , currW , val , wt,dp);
    int take = 0;
    if(currW >= wt[ind]){
        take = val[ind] +  f(ind , currW-wt[ind] , val ,wt,dp);
    }
    
    return dp[ind][currW] =  max(take , not_take);
}
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>>dp(N+1 , vector<int>(W+1, -1));
        return f(N-1 , W , val ,wt,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends