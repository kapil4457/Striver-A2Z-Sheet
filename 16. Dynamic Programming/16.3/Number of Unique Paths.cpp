//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int f(int a , int b , int x , int y , vector<vector<int>>&dp){
        if(x==0 && y==0){
            return 1;
        }
        
        if(x >=a || y>=b || x<0 || y<0)return 0;
        
        if(dp[x][y]!=-1)return dp[x][y];
        int bottom =  f(a , b , x-1 , y  , dp);
        int right =  f(a , b , x , y-1 , dp);
        
        return dp[x][y] =  bottom+right;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        vector<vector<int>>dp(a , vector<int>(b,-1));
        return f(a , b , a-1 , b-1 , dp);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends