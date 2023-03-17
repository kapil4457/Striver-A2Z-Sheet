//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        
        int left = 0 , right = n-1;
        
        
        while(left < right){
            int mid = (left+right)/2;
            if(k==arr[mid]){
                return mid;
            }else if(k==arr[left]){
                return left;
            }else if(k==arr[right]){
                return right;
            }else if(k > arr[mid]){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];
        int key;
        cin >> key;
        Solution ob;
        int found = ob.binarysearch(arr, N, key);
        cout << found << endl;
    }
}

// } Driver Code Ends