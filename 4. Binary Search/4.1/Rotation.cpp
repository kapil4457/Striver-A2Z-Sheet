//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int low = 0;
	    int high = n-1;
	    
	    //array is sorted -> No Rotation
	    if(arr[low]<arr[high])return 0;
	    
	    // There is only single element in array -> No Rotation
	    if(arr[low]==arr[high])return 0;
	    
	    
	    while(low<=high)
	    {
	        int mid = (low+high)>>1;
	        
	        if(mid<high && arr[mid]>=arr[mid+1])return mid+1; 
	        if(mid>low  &&arr[mid-1]>=arr[mid])return mid;
	        
	        if(arr[low]<=arr[mid])//left part is sorted
	            low = mid + 1; //discard that part
	        else high  = mid-1;    
	        
	    }
	    
	    return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends