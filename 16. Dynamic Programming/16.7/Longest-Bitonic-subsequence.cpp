//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int f(int ind , int prev_ind , int dir , vector<int>&nums ,int n ,  vector<vector<vector<int>>>&dp){
	    
	    if(ind==n)return 0;
	    
	    
	    if(dp[ind][prev_ind+1][dir]!=-1)return dp[ind][prev_ind+1][dir];
	    int take =0;
	    if(dir==1 && nums[prev_ind] < nums[ind]){
	        take = 1 + max(f(ind+1 , ind , dir , nums , n,dp)  ,f(ind+1 , ind , !dir  , nums , n ,dp));
	    }else if(dir==0 && nums[prev_ind] > nums[ind] ){
	        take = 1+ f(ind+1 , ind , dir , nums,n,dp);
	    }
	    
	    int not_take = 0 +f(ind+1 , prev_ind , dir , nums , n , dp);
	    return  dp[ind][prev_ind+1][dir] =max(take , not_take);
	}
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int prev_ind =-1 , ind =0 , dir =1 , n=  nums.size();
	    vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(n+1 , vector<int>(2 , -1)));
	   // memoization :
	    return f(ind , prev_ind , dir , nums , n , dp);
	 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends