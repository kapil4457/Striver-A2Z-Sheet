// Pattern :
// ****
// *  *
// *  *
// ****

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printSquare(int n)
    {
        int k = -1;
        for (int i = 1; i <= n; i++)
        {
            if (i <= n)
                k++;
            else
                k--;

            for (int j = 1; j <= n; j++)
            {
                if (i == 1 || i == n || j == 1 || j == n)
                {
                    cout << "*";
                }
                else
                    cout << " ";
            }

            cout << "\n";
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
        ob.printSquare(n);
    }
    return 0;
}
// } Driver Code Ends
