// Pattern :

// 1
// 2 3
// 4 5 6
// 7 8 9 10
// 11 12 13 14 15
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

        int num = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i + 1; j++)
            {
                cout << num << " ";
                num++;
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