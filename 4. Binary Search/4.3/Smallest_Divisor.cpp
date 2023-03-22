//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
  bool isValidSolution(vector<int>&nums , int m , int K){
      int tempSum= 0;
      int n = nums.size();
      for(int i=0 ; i  < n ; i ++){
          int num = ceil(nums[i]/m);
          tempSum+=num;
        if(nums[i]%m != 0) tempSum++;

      }
      
      if(tempSum <= K )return true;

      return false;
  }
    int smallestDivisor(vector<int>& nums, int K) {

int l = 1;
int h  =INT_MIN;
int n = nums.size();
for(int i=0 ; i < n  ; i ++){
    h = max(nums[i] , h);
}
int ans = INT_MAX;
while(l <= h){
    int m = l + (h-l)/2;
    
    if(isValidSolution(nums , m , K)){
        ans  = min(m , ans);
        h = m-1;
    }else{
        l = m+1;
    }
}

return ans;
        // Write your code here.
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    // cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n=4, k=6;
        // cin >> n >> k;
        // vector<int> vec(n);
        vector<int> vec={1,2,5,9};
        // for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends