//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    void helper(long long N, vector<long long> &ans, long long currMul, long long currNum)
    {

        int tempMul = currMul * currNum;
        if (tempMul >= N)
        {
            return;
        }
        ans.push_back(currNum);
        helper(N, ans, tempMul, currNum + 1);
    }
    vector<long long> factorialNumbers(long long N)
    {
        // Write Your Code here
        vector<long long> ans;
        helper(N, ans, 1, 1);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends