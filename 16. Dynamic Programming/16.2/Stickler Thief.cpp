//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int helper(vector<int>&dp , int arr[] , int n){
        if(n==0)return arr[0];
        if(n < 0)return 0;
        if(dp[n]!=-1)return dp[n];
        
        int take = arr[n] +  helper(dp , arr , n-2);
        int not_take = 0 +  helper(dp , arr , n-1);
        return dp[n]=   max(take , not_take);
    }
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        
        // memoization : 
        // vector<int>dp(n , -1);
        // return helper(dp , arr , n-1);
        
        
        // tabulation : 
        
        // vector<int>dp(n , -1);
        // dp[0] = arr[0];
        
        // for(int i=1 ; i <n ; i ++){
            
        //     int take = i-2>=0 ?  arr[i] + dp[i-2] : arr[i];
        //     int not_take = 0 + dp[i-1];
        //     dp[i] = max(take , not_take);
        // }
        // return dp[n-1];
        
        // Space Iotimization : 
        int one = arr[0];
        int two = INT_MAX;
        
        for(int i =1 ; i < n ; i++){
            int take = i-2>=0 ? arr[i]+two : arr[i];
            int not_take = 0 + one;
            two = one;
            one = max(take , not_take);
        }
        return one;
        
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
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends