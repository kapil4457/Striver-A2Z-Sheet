//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
// aabacbebebe
class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
    int n = s.length();
    int len = -1;
    int head = 0 , tail =0;
    map<char,int>ref;
    
    for(head = 0 ; head < n ;head ++){
        
        ref[s[head]]++;
        
        
        if(ref.size() == k){
            len = max(len , head-tail+1);
        }else if(ref.size() < k){
            continue;
        }else{
            while(tail < head){
               ref[s[tail]]--;
               if(ref[s[tail]]==0){
                   ref.erase(s[tail]);
                   tail++;
                   break;
               }
                   tail++;
            }
        }
        
        
        len = max(len , head-tail+1);
       
        
        
    }
    
    return len;
    }
};

//{ Driver Code Starts.
int main() {
    int t=1;
    // cin >> t;
    while (t--) {
        string s="aabacbebebe";
        // cin >> s;
        int k=3;
        // cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends