//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int N)
    {
        // Your code here
        sort(arr, arr + N);
        int c = 1, ans = 1;
        if (N == 0)
        {
            return 0;
        }
        for (int i = 1; i < N; i++)
        {
            if (arr[i] == arr[i - 1] + 1)
            {
                c++;
            }
            else if (arr[i] == arr[i - 1])
            {
                continue;
            }
            else
            {
                c = 1;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t, n, i, a[100001];
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.findLongestConseqSubseq(a, n) << endl;
    }

    return 0;
}
// } Driver Code Ends