// Pattern :
// 1                 1
// 1 2             2 1
// 1 2 3         3 2 1
// 1 2 3 4     4 3 2 1
// 1 2 3 4 5 5 4 3 2 1
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

        for (int i = 1; i <= n; i++)
        {
            // Left Side
            for (int j = 0; j < i; j++)
            {
                cout << j + 1 << " ";
            }
            // Blanks
            int blanks = ((2 * n) - (2 * i)) * 2;
            for (int j = 0; j < blanks; j++)
            {
                cout << " ";
            }

            // Right Side

            for (int j = i; j > 0; j--)
            {
                cout << j << " ";
            }

            cout << endl;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    // int t;
    // cin >> t;
    // while (t--)
    // {
    int n = 5;
    // cin >> n;

    Solution ob;
    ob.printTriangle(n);
    // }
    return 0;
}
// } Driver Code Ends