//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    int setBit(int N)
    {
        // Write Your Code here
        int mask = 1;
        int i = 0;
        while(N & mask  && mask<= N){
            mask <<= 1;
            i++;
        }
        
        if(mask>=N)return N;
        else{
            return mask|N;
        }
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends