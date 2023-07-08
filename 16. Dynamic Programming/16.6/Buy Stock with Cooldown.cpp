//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    
        long long  getAns(vector<long long>&Arr, int n, int ind, int buy, vector<vector<long long>>& dp  ){

    if(ind>=n ) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    long long  profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,n,ind+1,0,dp), 
                    -Arr[ind] + getAns(Arr,n,ind+1,1,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,n,ind+1,1,dp),
                    Arr[ind] + getAns(Arr,n,ind+2,0,dp));
    }
    
    return dp[ind][buy] = profit;
}
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
      vector<vector<long long >> dp(n,vector<long long > (2 , -1));
    
    return getAns(prices,n,0,0,dp );
    
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