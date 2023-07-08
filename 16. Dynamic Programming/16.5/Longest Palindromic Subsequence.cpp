//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int f(int front , int end , string s , vector<vector<int>>&dp){
      if(front == end)return 1;
      if(front > end)return 0;
      
      
      
      if(dp[front][end]!=-1)return dp[front][end];
      int take = 0;
      if(s[front]==s[end]){
          take = 2 + f(front+1 , end-1 , s,dp);
          
      }
      
      int not_take = max(f(front+1 , end , s,dp) , f(front , end-1 , s,dp));
      return dp[front][end] = max(take , not_take);
  }
    int longestPalinSubseq(string A) {
        //code here
        int n =A.length();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        return f(0 , n-1 ,A , dp) ;
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends