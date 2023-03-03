//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> Solve(int size, vector<int> &a)
    {
        // Code here
        // your code here
        int ele;
        int cnt = 0;

        map<int, int> ref;
        for (int i = 0; i < size; i++)
        {
            ref[a[i]]++;
        }

        vector<int> ans;
        for (auto it : ref)
        {
            if (it.second > size / 3)
            {
                ans.push_back(it.first);
            }
        }

        if (ans.size() == 0)
        {
            return {-1};
        }

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
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            a.push_back(x);
        }
        Solution obj;

        vector<int> res = obj.Solve(n, a);

        for (auto x : res)
            cout << x << " ";

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends