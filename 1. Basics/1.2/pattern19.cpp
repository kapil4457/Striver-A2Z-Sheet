// Pattern :
// **********
// ****  ****
// ***    ***
// **      **
// *        *
// *        *
// **      **
// ***    ***
// ****  ****
// **********

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

        // Top half

        int spaces = 0;
        for (int i = n; i > 0; i--)
        {
            // Left
            for (int j = 0; j < i; j++)
            {
                cout << "*";
            }

            // Spaces
            for (int j = 0; j < spaces; j++)
            {
                cout << " ";
            }
            spaces += 2;

            // Right

            for (int j = 0; j < i; j++)
            {
                cout << "*";
            }

            cout << endl;
        }

        // Bottom half

        int spaces2 = spaces - 2;
        for (int i = 0; i < n; i++)
        {
            // Left
            for (int j = 0; j < i + 1; j++)
            {
                cout << "*";
            }

            // Spaces
            for (int j = 0; j < spaces2; j++)
            {
                cout << " ";
            }
            spaces2 -= 2;

            // Right

            for (int j = 0; j < i + 1; j++)
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