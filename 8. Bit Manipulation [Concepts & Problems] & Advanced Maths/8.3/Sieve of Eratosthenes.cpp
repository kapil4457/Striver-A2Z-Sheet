//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    
    vector<int> ans;
    
    vector<int> sieveOfEratosthenes(int n)
    {
        // Write Your Code here
        vector<bool> is_prime(n+1, true);
        
        is_prime[0] = is_prime[1] = 0;
        
        for(int i=2; i*i<=n; i++){
            if(is_prime[i]){
                for(int j=i*i; j<=n; j = j+i){
                    is_prime[j] = 0;
                }
            }
        }
        
        for(int i=2; i<=n; i++){
            if(is_prime[i]){
                ans.push_back(i);
            }
        }
        
        return ans;
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
        cin>>N;
        Solution ob;
        vector<int> primes  = ob.sieveOfEratosthenes(N);
        for(auto prime : primes) {
            cout<< prime <<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends