// Pattern  :
// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1

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

        for (int i = 0; i < n; i++)
        {
            bool temp;
            if (i % 2 == 0)
            {
                temp = true;
            }
            else
            {
                temp = false;
            }
            for (int j = 0; j < i + 1; j++)
            {
                cout << temp << " ";
                temp = !temp;
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