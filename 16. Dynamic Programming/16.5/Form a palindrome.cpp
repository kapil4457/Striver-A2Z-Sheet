//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public :
  
  int f(int front , int end  , string s,vector<vector<int>>&dp){
      if(front >= end)return 0;
      
      if(dp[front][end]!=-1)return dp[front][end];
      int equal = INT_MAX;
      
      if(s[front]==s[end]){
          equal =  f(front+1 , end-1 , s,dp);
      }
      int not_equal = 1 + min(f(front+1  , end , s , dp) , f(front , end-1 , s , dp));
      
      return dp[front][end] = min(equal , not_equal);
  }
    int countMin(string str){
    //complete the function here
    int n = str.length();
    vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
    return f(0 , n-1 , str ,dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends