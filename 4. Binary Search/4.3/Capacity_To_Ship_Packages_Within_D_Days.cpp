//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  
     bool bareMinimum(int arr[], int N, int D, int mid){
        
        int days = 0; // required
        int temp = 0; // temporary sum
        
        for(int i = 0; i < N; i++){
            
            int weight = arr[i];
            
            // can ship in the same day.
            if(temp + weight <= mid) temp += weight;
            
            // can not ship in the same day.
            else{
                days++;
                
                // update it.
                temp = weight;
            }
            
        }
        
        // for the last weight.
        if(temp != 0) days++;
        
        
        // check required days are less then the given days or not.
        return (days <= D);
        
        
    }
    int leastWeightCapacity(int arr[], int N, int D) {
        // code here
        
       int maxi = INT_MIN;
        int sum = 0;
        
        for(int i =0; i < N; i++){
            sum += arr[i];
            maxi = max(maxi, arr[i]);
        }
        
        // minimum capacity would be the maximum weight 
        // as we have to ship the whole weight together.
        int low = maxi;
        int high = sum;
        int ans = -1;
        
        while(low <= high){
            
            int mid = low + (high - low)/2;
            
            if( bareMinimum(arr, N, D, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid +1;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends