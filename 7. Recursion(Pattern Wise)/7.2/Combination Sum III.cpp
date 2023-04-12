//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  void helper(vector<vector<int>>&ans , vector<int>&temp , int MaxSize, int sum , int currNum , int currSum){
      if(currNum>9){
          if(temp.size()==MaxSize && currSum==sum){
              ans.push_back(temp);
          }
              return;
      }
      
    //   take this number
    if(currSum+currNum <= sum){
        temp.push_back(currNum);
        helper(ans , temp , MaxSize , sum , currNum+1 , currSum+currNum);
        temp.pop_back();
    }
    // not take this number
        helper(ans , temp , MaxSize , sum , currNum+1 , currSum);
  }
    vector<vector<int>> combinationSum(int K, int N) {
        // code here
        vector<vector<int>>ans;
        vector<int>temp;
        int i =1;
        int currSum = 0;
        helper(ans , temp , K , N , i,  currSum);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K >> N;

        Solution obj;
        vector<vector<int>> ans = obj.combinationSum(K, N);
        sort(ans.begin(), ans.end());
        for (auto &arr : ans) {
            for (auto it : arr) cout << it << ' ';
            cout << endl;
        }
    }
    return 0;
}
// } Driver Code Ends