//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int gcd(int a, int b)
    {
        if (a == 0)
        {
            return b;
        }
        return gcd(b % a, a);
    }

    vector<long long> lcmAndGcd(long long A, long long B)
    {
        vector<long long> ans;
        ans.push_back((A * B) / (gcd(A, B))); // for LCM
        ans.push_back(gcd(A, B));             // for GCD
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
        long long A, B;

        cin >> A >> B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
// } Driver Code Ends