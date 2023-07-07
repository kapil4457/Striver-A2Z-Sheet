//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  
  public:
int long long func(int ind,vector<int long long> &dp,int long long mod){
        if(ind==0) return 0;
        if(ind==1) return 1;
        
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=(func(ind-1,dp,mod)+func(ind-2,dp,mod))%mod;
    }
  long long helper2(int n){
      
  }
    long long int topDown(int n) {
        // code here
          int long long mod=1e9+7;
        vector<int long long> dp(n+1,-1);
        return func(n,dp,mod);
    }
    long long int bottomUp(int n) {
   int long long dp[n+1];
        // code here
        int long long mod=1e9+7;
        dp[0]=0;
        if(n==0) return 0;
        
        dp[1]=1;
        if(n==1) return 1;
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]+dp[i-2])%mod;
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends