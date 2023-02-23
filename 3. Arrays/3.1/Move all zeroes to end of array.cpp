//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void pushZerosToEnd(int arr[], int n)
    {
        // code here
        int l = 0;
        int h = 0;
        while (h < n)
        {
            if (arr[l] > 0)
            {
                l++;
                h++;
            }
            else
            {

                if (arr[h] > 0)
                {
                    swap(arr[l], arr[h]);
                    l++;
                }
                h++;
            }
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
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        ob.pushZerosToEnd(arr, n);
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends