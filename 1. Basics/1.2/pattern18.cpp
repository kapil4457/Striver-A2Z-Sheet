// Pattern :
// E
// E D
// E D C
// E D C B
// E D C B A

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
        int temp = 65 + n - 1;

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < i + 1; j++)
            {
                cout << (char)(temp - j) << " ";
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