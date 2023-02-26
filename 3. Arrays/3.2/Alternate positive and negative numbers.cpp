//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        // code here
        queue<int> a, b;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                b.push(arr[i]);
            }
            else
            {
                a.push(arr[i]);
            }
        }

        int i = 0;

        while (a.size() != 0 && b.size() != 0)
        {
            if (i % 2 == 0)
            {
                arr[i] = a.front();
                a.pop();
            }
            else
            {
                arr[i] = b.front();
                b.pop();
            }
            i++;
        }

        while (a.size() != 0)
        {
            arr[i] = a.front();
            i++;
            a.pop();
        }

        while (b.size() != 0)
        {
            arr[i] = b.front();
            i++;
            b.pop();
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
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends