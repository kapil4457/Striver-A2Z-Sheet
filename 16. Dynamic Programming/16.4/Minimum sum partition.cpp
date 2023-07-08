//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
  
  
  int f(int arr[] , int n , int currSum , int totalSum , vector<vector<int>>&dp){
      
      
      if(n==0){
          int left = totalSum - currSum;
          return abs(currSum - left);
      }
      
      if(dp[n][currSum] !=-1)return dp[n][currSum];
      int take = f(arr , n-1  , currSum+arr[n] , totalSum , dp);
      int not_take = f(arr , n-1  , currSum , totalSum,dp);
      
      return dp[n][currSum] = min(take , not_take);
  }
 
  
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totalSum = 0;
	    for(int i =0 ; i  < n ; i ++){
	        totalSum+=arr[i];
	        
	    }
	    vector<vector<int>>dp(n , vector<int>(totalSum , -1));
	    
	    return f(arr ,  n-1 , 0 , totalSum , dp);
	    
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends