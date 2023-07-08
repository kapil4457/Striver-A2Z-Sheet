//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
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
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n= str1.length() , m=str2.length();
	    return n+m -(2*lcs(n,m,str1,str2));
	    
	    
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends