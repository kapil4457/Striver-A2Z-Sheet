//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
   int closest3Sum(int a[], int n, int x)

    {

        sort(a,a+n);

        int diff = INT_MAX;

        int res;

        for(int i=0;i<n-2;i++){

            int j=i+1,k=n-1;

            while(j<k){

                int sum=(a[i]+a[j]+a[k]);

                if(diff>abs(x-sum)){

                    diff=abs(x-sum);

                    res=sum;

                }

                if(sum>x){

                    k--;

                }

                else if(sum<x){

                    j++;

                }

                else{

                    return x;

                }

            }

        }

        return res;

    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}
// } Driver Code Ends