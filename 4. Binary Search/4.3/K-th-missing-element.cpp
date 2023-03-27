//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int KthMissingElement(int a[], int n, int k);


int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        cout << KthMissingElement(a, n, k) << endl;
    
    }
    return 0;
}

// } Driver Code Ends


int KthMissingElement(int a[], int n, int k)
{
    int cnt = 0;
    int num = a[0];
    
    int j = 0;
    while(j < n){
        if(num == a[j]){
            num++;
            j++;
        }
        else{
            cnt++;
            if(cnt == k)
                return num;
            num++;
        }
    }
    
    return -1;
}