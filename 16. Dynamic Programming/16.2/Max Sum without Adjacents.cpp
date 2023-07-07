//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int helper(int *arr , vector<int>&dp  , int n){
	   if(n<0)return 0;
	   if(n==0)return arr[n];
	   if(dp[n]!=-1)return dp[n];
	   
	   int pick = arr[n]+ helper(arr , dp  , n-2);
	   int not_pick = 0 + helper(arr , dp , n-1);
	   return dp[n] = max(pick , not_pick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	    
	    
	    
	   // Memoization  : 
	   
	   // vector<int>dp(n , -1);
	   // return helper(arr , dp ,n-1);
	    
	    
	   // tabulation : 
	   //vector<int>dp(n , -1);
	   //dp[0] = arr[0];
	   //int neg = 0;
	   
	   //for(int i = 1 ; i < n ; i ++){
	       
	       
	   //    int take = neg;
	   //    take = i-2>=0 ?  arr[i] + dp[i-2] : arr[i];
	   //    int not_take = 0 + dp[i-1];
	   //    dp[i] = max(take , not_take);
	   //}
	   // return dp[n-1];
	    
	    
	    
	   // Space Optimization : 
	   int one = arr[0];
	   int two = -1;
	   for(int i =1 ; i < n ; i++){
	       int take = i-2>=0 ? arr[i] + two : arr[i];
	       int not_take = 0 + one;
	       two = one;
	       one = max(take , not_take);
	   }
	   return one;
	   
	
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends