//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
  void helper(vector<vector<int>>&ans , vector<int>&nums , vector<int>&temp , int n , int i){
      if(temp.size()==0){
          ans.push_back(temp);
      }
      if(i==n){
          return;
      }
      
    //   take
    for(int ind = i ; ind < nums.size() ; ind++){
        
        if(ind > i && nums[ind]==nums[ind-1])continue;
    temp.push_back(nums[ind]);
    ans.push_back(temp);
    helper(ans , nums, temp , n , ind+1);
    temp.pop_back();
    }
    // not take
  }
    vector<vector<int>> printUniqueSubsets(vector<int>& nums) {
        // Write your code here
        vector<vector<int>>ans;
        sort(nums.begin(), nums.end());
        vector<int>temp;
        int i= 0;
        int n = nums.size();
        helper(ans , nums , temp , n , i);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;
        vector<vector<int>> ans = obj.printUniqueSubsets(nums);
        sort(ans.begin(), ans.end());
        //   printAns(ans);
        cout << "[ ";
        for (int i = 0; i < ans.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j] << " ";
            cout << "]";
        }
        cout << " ]\n";

        // cout<< "~\n";
    }

    return 0;
}

// } Driver Code Ends