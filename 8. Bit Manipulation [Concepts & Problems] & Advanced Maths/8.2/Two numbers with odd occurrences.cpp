//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int  xorAns = 0;
        for(int i =0 ; i < N  ;i ++){
            xorAns^= Arr[i];
        }
        
        long long cnt =0 ;
        
        while(xorAns){
            if(xorAns & 1){
                break;
            }
            cnt++;
            xorAns >>= 1;
        }
        
        long long mask = 1 << cnt;
        
        long long set = 0;
        long long unset = 0;
        for(int i =0 ; i <  N  ; i ++){
            if(Arr[i]&mask){
                set^=Arr[i];
            }else{
                unset^=Arr[i];
            }
        }
        
        return {max(set,unset) , min(unset,set)};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends