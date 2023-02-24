//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {
        // code here
        int zero = 0;
        int one = 0;
        int two = 0;

        for (int i = 0; i < n; i++)
        {

            if (a[i] == 1)
            {
                one++;
            }

            if (a[i] == 0)
            {
                zero++;
            }

            if (a[i] == 2)
            {
                two++;
            }
        }

        int ind = 0;

        while (zero--)
        {
            a[ind] = 0;
            ind++;
        }

        while (one--)
        {
            a[ind] = 1;
            ind++;
        }

        while (two--)
        {
            a[ind] = 2;
            ind++;
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends