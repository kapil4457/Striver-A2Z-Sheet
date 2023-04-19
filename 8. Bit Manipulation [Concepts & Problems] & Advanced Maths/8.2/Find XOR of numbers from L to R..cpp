//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
//    By mod 4 if the  remainder is  : 
//   0 : print n
//   1 : print 1
//   2 : print (n+1)
//   3 : print 0
    int findXOR(int l, int r) {
        // complete the function here
        
        
        int xorR  , xorL ;
        if(r%4==0){
            xorR = r;
        }else if(r%4==1){
            xorR = 1;
            
        }else if(r%4==2){
            xorR = r+1;
            
        }else if(r%4==3){
            xorR = 0;
            
        }
        
        
        if((l-1)%4==0){
            xorL = l-1;
        }else if((l-1)%4==1){
            xorL = 1;
            
        }else if((l-1)%4==2){
            xorL = l;
            
        }else if((l-1)%4==3){
            xorL = 0;
            
        }
        
        
        return xorR ^ xorL;
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        // Input

        int l, r;
        cin >> l >> r;

        Solution obj;
        cout << obj.findXOR(l, r) << endl;
    }
}
// } Driver Code Ends