//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        queue<int>ref;
        int j =0 ;
        int i =1;
     while(i < n){
         
         if(a[i] > a[j]){
                return false;
         }
         i++;
         if(i >= n)break;
         if(a[i] > a[j]){
                return false;
         }
         i++;
         j++;
     }
     return true;
    }
};

//{ Driver Code Starts.
int main() {
    
    int t=1;
    // cin >> t;
    while(t--)
    {
       int n=6;
    //    cin >> n;
    //    int a[4*n]={0};
       int a[4*n]={90 ,  15 , 10 ,  7 , 12, 2};
    //    for(int i =0;i<n;i++){
    //        cin >> a[i];
    //    }
       Solution ob;
       cout<<ob.isMaxHeap(a, n)<<endl;
        
    }
    return 0;
}

// } Driver Code Ends