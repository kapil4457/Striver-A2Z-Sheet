//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
//   Recursive Solution : O(2^n)

  bool helper(int A[] , int N , int currIdx){
      if(currIdx==N-1)return true;
      if(A[currIdx]==0)return false;
      bool ans = false;
      for(int i = currIdx+1 ; i <= min(currIdx+A[currIdx] , N-1) ; i ++){
    bool tempAns =   helper(A , N , i);
    
    if(tempAns == true){
        ans = tempAns;
    }
      }
      
      
      return ans;
  }
  
  
  
    int canReach(int A[], int N) {
        // code here
        
        // Approach 1 : Recursion 
        // return helper(A , N , 0);
        
        
        // Approach 2 : Greedy
        
        int reachable = 0;
       
       for(int i =0 ; i <  N ; i++){
           if(reachable < i)return false;
           
           reachable = max(reachable , i+A[i]);
       }
       
       return true;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}
// } Driver Code Ends