// Pattern :
// 4 4 4 4 4 4 4
// 4 3 3 3 3 3 4
// 4 3 2 2 2 3 4
// 4 3 2 1 2 3 4
// 4 3 2 2 2 3 4
// 4 3 3 3 3 3 4
// 4 4 4 4 4 4 4

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printSquare(int n)
    {
        int k, var = -1;
        for (int i = 1; i <= 2 * n - 1; i++)
        {
            k = n;
            if (i <= n)
                var++;
            else
                var--;

            for (int j = 1; j <= 2 * n - 1; j++)
            {
                cout << k << " ";

                if (j <= var)
                    k--;
                else if (j >= 2 * n - var - 1)
                    k++;
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