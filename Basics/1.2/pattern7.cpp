//{ Driver Code Starts

// Pattern :
//     *
//    ***
//   *****
//  *******
// *********
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printTriangle(int n)
    {
        // code here

        int oddNum = 1;

        for (int i = 0; i < n; i++)
        {

            // printing spaces
            for (int j = 0; j < n - i + 1; j++)
            {

                cout << " ";
            }
            // printing stars
            for (int j = 0; j < oddNum; j++)
            {
                cout << "*";
            }
            oddNum += 2;
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