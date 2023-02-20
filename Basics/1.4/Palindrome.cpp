
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    string is_palindrome(int n)
    {
        // Code here.
        string s = to_string(n);
        //  cout<<"s : " <<s<<endl;

        int j = s.size() - 1;

        bool check = true;
        for (int i = 0; i < s.size() / 2; i++)
        {
            if (s[i] == s[j])
            {
                j--;
                continue;
            }
            else
            {
                check = false;
            }
        }

        if (check)
        {
            return "Yes";
        }
        else
        {
            return "No";
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        Solution ob;
        string ans = ob.is_palindrome(n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends