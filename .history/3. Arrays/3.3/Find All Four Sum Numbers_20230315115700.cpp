//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        
        for(int i=0;i<n-3;i++)
        {
            if(arr[i]!=arr[i-1] || i==0)
            {
                for(int j=i+1;j<n-2;j++)
                {
                    if(j==i+1 || arr[j]!=arr[j-1])
                    {
                        int target = k-arr[i]-arr[j];
                        int low=j+1,high=n-1;
                        
                        while(low<high)
                        {
                            if(arr[low]+arr[high]==target)
                            {
                                ans.push_back({arr[i],arr[j],arr[low],arr[high]});
                                low++;
                                high--;
                                while(low<high && arr[low]==arr[low-1]) low++;
                                while(low<high && arr[high]==arr[high+1]) high--;
                            }
                            else if(arr[low]+arr[high]>target)
                            {
                                high--;
                            }
                            else {
                                low++;
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends