//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int longestOnes(int n, vector<int>& nums, int k) {
        // Code here
        int l = 0;
        int r = 0;
        queue<int>q;
        int ans =-1;
        while(r<n){
            if(nums[r]==1){
                r++;
                // ans = max(ans , r-l);
            }else
                // ans = max(ans , r-l);
            if(k!=0){
                q.push(r);
                nums[r]=1;
                r++;
                k--;
                // ans = max(ans , r-l);
            }else{
                l = q.front();
                nums[l]=0;
                l++;
                q.pop();
                
                nums[r]=1;
                q.push(r);
                r++;
            }
                ans = max(ans , r-l);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.longestOnes(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends