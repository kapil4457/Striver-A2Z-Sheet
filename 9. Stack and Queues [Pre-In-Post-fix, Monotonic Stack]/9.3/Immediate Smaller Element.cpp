//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    //  code here
	     stack<int >st;
	             st.push(-1);

         vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--)
        {
           // while(st.top() >= arr[i])
           // {
           //     st.pop();
           // }
            if(st.top() < arr[i]) ans[i]=st.top();
            else ans[i]=-1;
            
            st.push(arr[i]);
        }
        
        for(int i=n-1;i>=0;i--)
        {
            arr[i]=ans[i];
        }
	}
	

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends