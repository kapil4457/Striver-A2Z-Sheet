//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

int f(int arr[] , int currSum , int idx,  vector<vector<int>>&dp){
    
    if(currSum==0)return true;
    if(idx==0)return arr[0]==currSum;
    if(idx < 0)return 0;
    if(currSum < 0)return 0;
    if(dp[idx][currSum]!=-1)return dp[idx][currSum];
    
    bool not_take = f(arr , currSum , idx-1 , dp);
    bool take =false;
    if(arr[idx] <=currSum){
        
    take= f(arr , currSum-arr[idx] , idx-1 , dp);
    }
    
    return dp[idx][currSum] = take || not_take;
}
    int equalPartition(int n, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0 ; i < n ; i ++)sum+=arr[i];
        if(sum%2!=0)return 0;
              
        vector<vector<int>>dp(n+1 , vector<int>(100001 , -1));
        return f(arr , sum/2 , n-1 , dp);
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends