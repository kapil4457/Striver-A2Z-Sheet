//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n, 1e7 + 1);
        int ans = solve(arr, dp, 0, n);
        if (ans == 1e7 + 1)
            return -1;

        return ans;
    }

    int solve(int *nums, vector<int> &dp, int pos, int n)
    {
        if (pos >= n - 1)
            return 0;
        if (dp[pos] != 1e7 + 1)
            return dp[pos];
        for (int j = 1; j <= nums[pos]; j++)
            dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j, n));
        return dp[pos];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends