//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
              if (x == 0 || x == 1)
                        return x;
       long long  high = x,
        low = 0;
        long long ans;
        while (low <= high){
            
          long long   mid = (high + low)/2;
            long long mid_sq = mid*mid;
            if (mid_sq == x){
                
                ans = mid;
                return ans  ;
            }
            else if (x > mid_sq){
                
                low = mid + 1;
                ans = mid ;
            }
            else{
                
                high = mid-1 ;
            }
        }
        return ans;

        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends