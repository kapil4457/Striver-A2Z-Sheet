//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
 void func(vector<int> &arr,int tar,int idx, vector<vector<int>> &ans, vector<int> &temp)
    {
        if(idx==arr.size())
        {
            if(tar==0)
                ans.push_back(temp);
            return;
        }
        
        if(arr[idx]<=tar)
        {
            temp.push_back(arr[idx]);
            func(arr,tar-arr[idx],idx+1,ans,temp);
            
            while(idx<arr.size()-1 && arr[idx]==arr[idx+1])
                idx++;
            
            temp.pop_back();
        }
        
        func(arr,tar,idx+1,ans,temp);
    }
    
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        // Write your code here
        
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(candidates.begin(), candidates.end());
        func(candidates,target,0,ans,temp);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends