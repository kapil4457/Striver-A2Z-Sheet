//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{

public:
    int findK(vector<vector<int>> &a, int n, int m, int k)

    {

        // Your code goes here

        int l = 0, r = m, top = 0, bot = n, count = 0;

        while (l < r && top < bot)

        {

            // Taking topmost row

            for (int i = l; i < r; i++)

            {

                count++;

                if (count == k)

                    return a[top][i];
            }

            top++;

            // Taking rightmost column

            for (int i = top; i < bot; i++)

            {

                count++;

                if (count == k)

                    return a[i][r - 1];
            }

            r--;

            // checking validity

            if (l >= r || top >= bot)

                return -1;

            // Taking bottommost column

            for (int i = r - 1; i >= l; i--)

            {

                count++;

                if (count == k)

                    return a[bot - 1][i];
            }

            bot--;

            // Taking leftmost column

            for (int i = bot - 1; i >= top; i--)

            {

                count++;

                if (count == k)

                    return a[i][l];
            }

            l++;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int n, m;
        int k = 0;
        // cin>>k;
        cin >> n >> m >> k;
        vector<vector<int>> a(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }

        Solution obj;

        cout << obj.findK(a, n, m, k) << "\n";
    }
}
// } Driver Code Ends