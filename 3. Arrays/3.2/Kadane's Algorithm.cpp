//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // arr: input array
    // n: size of array
    // Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int a[], int n)
    {

        // Your code here
        int max_so_far = INT_MIN;
        int maxSum = 0;

        for (int i = 0; i < n; i++)
        {
            maxSum += a[i];

            if (max_so_far < maxSum)
            {
                max_so_far = maxSum;
            }

            if (maxSum < 0)
            {
                maxSum = 0;
            }
        }

        return max_so_far;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends