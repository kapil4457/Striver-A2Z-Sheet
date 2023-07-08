//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
 int f(int ind , int prev_ind , int arr[] , int n , vector<vector<int>>&dp){
     if(n==ind)return 0;
     
     if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
     int len = 0 + f(ind+1 , prev_ind , arr , n , dp);
     if(prev_ind==-1 || arr[prev_ind] < arr[ind]){
         len = max(len ,  1 + f(ind+1 , ind , arr , n , dp));
     }
     return dp[ind][prev_ind+1]=len;
     
 }
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       
       
    //   memoization :
    //   vector<vector<int>>dp(n , vector<int>(n+1 , -1));
    //   return f(0,-1,a,n , dp);
    
    
    // tabulation : 
    //   vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));
      
    //   for(int ind =n-1 ; ind >=0 ; ind--){
    //       for(int prev_ind = ind-1 ; prev_ind >=-1; prev_ind--){
    //             int len = 0 + dp[ind+1][ prev_ind+1];
    //              if(prev_ind==-1 || arr[prev_ind] < arr[ind]){
    //                  len = max(len ,  1 +dp[ind+1][ind+1] );
    //              }
    //               dp[ind][prev_ind+1]=len;
    //       }
    //   }
    //   return dp[0][0];
      
      
    //   Binary Search : 
    
    vector<int>temp;
    temp.push_back(arr[0]);
    for(int i =1 ; i < n;  i ++){
        if(arr[i] > temp.back()){
            temp.push_back(arr[i]);
            continue;
        }
       int j=lower_bound(temp.begin(), temp.end(), arr[i])-temp.begin();
               temp[j]=arr[i];

    }
    
    return temp.size();
      
       
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends