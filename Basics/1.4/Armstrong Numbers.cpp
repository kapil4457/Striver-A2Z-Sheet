//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    string armstrongNumber(int n)
    {
        // code here
        long long sum = 0;

        int tempNum = n;

        while (n)
        {

            int remainder = n % 10;
            sum += (remainder * remainder * remainder);
            n /= 10;
        }
        if (sum == tempNum)
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends