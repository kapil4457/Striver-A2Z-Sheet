//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int helper(vector<int>&dp , vector<int>&height , int n ,int k){
      if(n==0)return 0;
      
      if(dp[n]!=-1)return dp[n];
      
      int mini = INT_MAX;
      for(int i =1 ; i <= k && n-i >=0 ; i ++){
          int tmpAns = helper(dp  , height , n-i , k) + abs(height[n] - height[n-i]);
          mini = min(mini , tmpAns);
      }
      
     return dp[n]= mini;
  }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        
        // memoization : 
        // vector<int>dp(n,-1);
        // return helper(dp , height , n-1 , k);
        
        
        // tabulation : 
        vector<int>dp(n);
        dp[0] = 0;
        
        for(int i =1 ; i < n ;  i ++){
        int mini = INT_MAX;    
            for(int j = 1 ; j <= k && i-j >=0 ;j++){
                int tmpAns = dp[i-j] + abs(height[i-j] - height[i]);
                mini = min(mini , tmpAns);
            }
            
            dp[i] = mini;
        }
        
        return dp[n-1];
        
        
       
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends