//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int f (vector<int>&A , int target , int idx , int currSum){
      if(currSum==target && idx<0)return 1;
      if(idx<0)return 0;
      
      int positive = f(A , target , idx-1 , currSum+A[idx]);
      int negative = f(A , target , idx-1 , currSum-A[idx]);
      return  positive+negative;
  }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int ans = 0 ;
        int n = A.size();
        ans += f(A , target , n-2 , -A[n-1] );
        ans += f(A , target , n-2 , A[n-1] );
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends