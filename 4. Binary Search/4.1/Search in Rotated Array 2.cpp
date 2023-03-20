//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
//   Worst case : O(n)
//   Average case : O(log N)
//   Space Complexity : O(1)
    bool Search(int N, vector<int>& A, int x) {
        int l = 0,
        h = A.size()-1;
        // Code here
     while(l <= h){
         int m = (h+l)/2;
         
         if(A[m]==x)return 1;
         
         // If left is sorted
        if(A[m] > A[l]){
            if(x <= A[m] && x>=A[l]){
                h = m-1;
            }else{
                l = m+1;
            }
        }else if(A[m] < A[l]){
            // If right is sorted
              if(x <= A[h] && x>=A[m]){
                l = m+1;
            }else{
                h = m-1;
            }
        }else{
            //If A[l] == A[r] == A[m]
            l++;
        }
         
     }
     return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int key;
        cin >> key;

        Solution obj;
        cout << obj.Search(n, a, key) << "\n";
    }
    return 0;
}
// } Driver Code Ends