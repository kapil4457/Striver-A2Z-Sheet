//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    	       int f(int x , int y, string s1 , string s2 , vector<vector<int>>&dp)
    {
        if(x < 0 || y < 0)return 0;
        
        
        if(dp[x][y]!=-1)return dp[x][y];
        
        int take = 0;
        if(s1[x] == s2[y]){
            take = 1 + f(x-1 , y-1 , s1 , s2,dp);
        }
        int not_take =max( f(x-1 , y , s1 , s2,dp) , f(x , y-1 , s1 , s2 , dp));
        return dp[x][y] =  max(take , not_take);
        
    }
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int>>dp(x , vector<int>(y+1 , -1));
        return f(x-1 , y-1 , s1 , s2 ,dp);
    }
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        return m+n - (lcs(m , n , X , Y));
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends