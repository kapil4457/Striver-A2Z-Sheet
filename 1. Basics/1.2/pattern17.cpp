//{ Driver Code Starts

// Pattern :
//    A
//   ABA
//  ABCBA
// ABCDCBA
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printTriangle(int n)
    {

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n - (i + 1); j++)

                cout << " ";

            for (int j = 0; j <= i; j++)

                cout << char('A' + j);

            int k = i - 1;

            for (int j = 0; j < i; j++)
            {

                cout << char('A' + k);

                k--;
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