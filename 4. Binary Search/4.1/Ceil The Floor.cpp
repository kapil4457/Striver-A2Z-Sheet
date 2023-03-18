//{ Driver Code Starts

#include <bits/stdc++.h>

using namespace std;

pair<int, int> getFloorAndCeil(int arr[], int n, int x);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        auto ans = getFloorAndCeil(arr, n, x);
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}

// } Driver Code Ends


pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
    // code here
   int smallest = INT_MIN;
   int biggest = INT_MAX;
   
   
   for(int i =0 ; i  < n ; i ++){
       if(arr[i] > x){
           biggest = min(arr[i],biggest);
       }else if(arr[i] < x){
           smallest = max(arr[i] , smallest);
       }else{
           biggest = arr[i];
           smallest = arr[i];
           break;
       }
   }
   
   if(smallest == INT_MIN)return {-1 , biggest};
   if(biggest == INT_MAX)return {smallest , -1};
   
   return {smallest , biggest};
        
}