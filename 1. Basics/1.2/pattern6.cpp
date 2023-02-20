//{ Driver Code Starts
// Pattern :
// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void printTriangle(int n)
    {
        // code here
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j < i + 1; j++)
            {
                cout << j + 1 << " ";
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