//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
 

  int  f(int ind , int prev_ind , int n ,vector<int>&arr, vector<int>&ans  ,  vector<int>&ref , vector<vector<int>>&dp){
     if(ans.size() > ref.size()){
         ref = ans;
     }
     if(ind ==n )return 0 ;
     
     int take = 0;
     if(prev_ind==-1 || arr[ind]%arr[prev_ind]==0){
         ans.push_back(arr[ind]);
         take = 1 + f(ind+1 , ind , n ,arr, ans ,ref  ,dp);
         ans.pop_back();
     }
        int not_take = f(ind+1 , prev_ind , n ,arr, ans , ref , dp);
     
     
     return max(take,not_take);
      
  }
  
    vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
        sort(arr.begin() , arr.end());
        vector<vector<int>>dp(n , vector<int>(n ,-1));
        int prev_ind = -1 , currInd = 0  , currSize = 0;
        vector<int>ans ;
        vector<int>ref ;
        f(currInd , prev_ind , n , arr , ans ,ref ,dp );
        return ref;   
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        vector<int> res = obj.LargestSubset(n, arr);
        int isValidSeq = 1, sz = res.size();
        for (int i = 0; i < sz; i++) {
            for (int j = i + 1; j < sz; j++) {
                if ((res[i] % res[j]) == 0 || (res[j] % res[i]) == 0)
                    continue;
                else {
                    isValidSeq = 0;
                    break;
                }
            }
        }
        cout << isValidSeq << " " << sz << endl;
    }
    return 0;
}
// } Driver Code Ends