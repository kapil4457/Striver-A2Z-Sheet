//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
    
long long f(int ind , int buy , vector<long long>&prices , int n , vector<vector<long long >>&dp){
    if(ind>=n)return 0;
    
    long long  profit = 0;
    
    if(dp[ind][buy]!=-1)return dp[ind][buy];
    
    if(buy){
     profit = max(-prices[ind] + f(ind+1 , 0 , prices , n , dp)  , 0 + f(ind+1 , 1 , prices , n,dp));   
    }else{
        profit = max(prices[ind] + f(ind+1  , 1 , prices , n ,dp) ,0 +  f(ind+1 , 0 , prices, n,dp));
    }
    
    return dp[ind][buy] =  profit;
}
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        
        vector<vector<long long >>dp(n+1 , vector<long long >(2 , -1));
        return f( 0 , 1 , prices , n , dp);
       
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends