// Pattern :
// *        *
// **      **
// ***    ***
// ****  ****
// **********
// ****  ****
// ***    ***
// **      **
// *        *

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printTriangle(int n)
    {
        // code here

        // Top Half

        for (int i = 0; i < n; i++)
        {
            // Left Half

            for (int j = 0; j < i + 1; j++)
            {
                cout << "*";
            }
            // Spaces

            for (int j = 0; j < (2 * n - 2 * (i + 1)); j++)
            {
                cout << " ";
            }

            // Right Half

            for (int j = 0; j < i + 1; j++)
            {
                cout << "*";
            }

            cout << endl;
        }

        // Bottom Half
        int spaces = 2;
        for (int i = n - 1; i > 0; i--)
        {
            // Left Half

            for (int j = i; j > 0; j--)
            {
                cout << "*";
            }
            // Spaces

            for (int j = 0; j < spaces; j++)
            {
                cout << " ";
            }
            spaces += 2;

            // Right Half

            for (int j = i; j > 0; j--)
            {
                cout << "*";
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