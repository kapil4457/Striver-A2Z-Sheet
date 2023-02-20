//{ Driver Code Starts
// Pattern :
// *********
//  *******
//   *****
//    ***
//     *
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printTriangle(int n)
    {
        // code here
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
            for (int j = 0; j < 2 * i - 1; j++)
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