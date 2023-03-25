//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string maxOdd(string s) {
        // your code here
        int n = s.length();
        
        string ans = "";
        int idx = -1;
        for(int i =n-1 ; i >=0  ; i --){
            if(s[i]=='1' || s[i]=='3' || s[i]=='5' || s[i]=='7' || s[i]=='9'){
                idx = i;
                break;
            }
            
        }
        
        if(idx==-1)return ans;
        for(int i =0 ; i <= idx ; i ++){
            ans.push_back(s[i]);
        }
return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;

        cout << ob.maxOdd(s) << endl;
    }
}

// } Driver Code Ends