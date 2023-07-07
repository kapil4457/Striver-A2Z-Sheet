//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
 int f(int n,vector<int>& height,vector<int>& dp){
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int left=f(n-1,height,dp)+abs(height[n]-height[n-1]);
        
        int right=INT_MAX;
        if(n>1){
            right=f(n-2,height,dp)+abs(height[n]-height[n-2]);
        }
        return dp[n]=min(right,left);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
      
    //   Memoization : 
        //   vector<int> dp(n,-1);
        
        // return f(n-1,height,dp);
        
        
    //  Tabulation : 
    // vector<int>dp(n , -1);
    // dp[0] = 0;

    // for(int i =1 ; i < n ; i ++){
    //     int right = INT_MAX;
    //     int left =dp[i-1] + abs(height[i-1] - height[i]);
    //     if(i > 1){
            
    //     right =dp[i-2] + abs(height[i-2] - height[i]);
    //     }
    //     dp[i] = min(left , right);
    // }
    
    // return dp[n-1];
    
    
    
    // Space Optimization : 
    
  int one = 0;
  int two = INT_MAX;


for(int i =1 ; i < n ; i ++){
    int right = INT_MAX;
    int left = one + abs(height[i-1] - height[i]);
    if(i > 1){
        right = two + abs(height[i-2] - height[i]);
    }
    
    two = one;
    one = min(right  , left);
    
}

return one;
    }
    
    
    
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends