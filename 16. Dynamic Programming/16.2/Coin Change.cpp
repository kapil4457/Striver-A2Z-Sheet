//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long int f(int coins[] , int idx , int sum , vector<vector<long long int>>&dp){
      if(idx==0)return sum % coins[idx]==0;
     
      
      if(dp[idx][sum]!=-1)return dp[idx][sum];
      long long int take = 0;
      if(coins[idx] <= sum){
          take += f(coins , idx , sum-coins[idx] , dp);
      }
      long long int not_take = f(coins , idx-1 , sum ,dp);
      return dp[idx][sum]=take+not_take;
  }
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<vector<long long  int>>dp(N+1,vector<long long int >(sum+1 , -1));
        return f(coins , N-1 , sum , dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends