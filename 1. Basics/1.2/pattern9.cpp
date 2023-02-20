// Pattern :
//     *
//    * *
//   * * *
//  * * * *
// * * * * *
// * * * * *
//  * * * *
//   * * *
//    * *
//     *

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printDiamond(int n)
    {
        // code here

        // Upper Half
        for (int i = 0; i < n; i++)

        {

            // space

            for (int j = 0; j < n - i - 1; j++)

            {

                cout << " ";
            }

            // star

            for (int j = 0; j < i + 1; j++)

            {

                cout << "* ";
            }

            cout << endl;
        }

        // Lower Half
        int spaces = 0;
        for (int i = n; i > 0; i--)
        {
            // Spaces
            for (int j = 0; j < spaces; j++)
            {
                cout << " ";
            }
            spaces++;
            // stars
            for (int j = 0; j < i; j++)
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
        ob.printDiamond(n);
    }
    return 0;
}
// } Driver Code Ends