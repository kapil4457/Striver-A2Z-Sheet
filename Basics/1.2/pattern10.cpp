// Pattern :
// *
// * *
// * * *
// * * * *
// * * * * *
// * * * *
// * * *
// * *
// *
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++
class Solution
{
public:
    void printTriangle(int n)
    {
        // code here

        // Upper Half

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                cout << "* ";
            }
            cout << endl;
        }

        // Lower Half

        for (int i = n - 1; i > 0; i--)
        {
            for (int j = i; j > 0; j--)
            {
                cout << "* ";
            }
            cout << endl;
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
        ob.printTriangle(n);
    }
    return 0;
}
// } Driver Code Ends