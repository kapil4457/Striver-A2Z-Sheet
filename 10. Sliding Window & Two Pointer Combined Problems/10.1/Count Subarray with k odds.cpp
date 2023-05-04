//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubarray(int n, vector<int>& arr, int k) {
         int count=0;
        int ans=0;
        int l=0,r=0;
        while(r<n){
            if(arr[r]%2==1)
            count++;
            
            if(count<k){
                r++;
            }
            else{
                if(count==k){
                    int temp=l;
                    int countTemp=count;
                   while(countTemp==k){
                    ans++;
                    if(arr[temp]%2==1)
                    countTemp--;
                    
                    temp++;
                }
                r++;
                }
                else{
                    while(count>k){
                        if(arr[l]%2==1)
                        count--;
                        l++;
                    }
                     int temp=l;
                    int countTemp=count;
                   while(countTemp==k){
                    ans++;
                    if(arr[temp]%2==1)
                    countTemp--;
                    
                    temp++;
                }
                    r++;
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
        int n;
        cin >> n;
        vector<int> nums;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        int k;
        cin >> k;

        Solution obj;
        cout << obj.countSubarray(n, nums, k) << endl;
    }
    return 0;
}
// } Driver Code Ends