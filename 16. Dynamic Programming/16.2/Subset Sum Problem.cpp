//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

int f(vector<int>&arr , int currSum , int idx,  vector<vector<int>>&dp){
    
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
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n+1 , vector<int>(100001 , -1));
        return f(arr , sum , n-1 , dp);
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends